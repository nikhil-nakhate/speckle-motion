#include <arrayfire.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace af;

#define fftshift(in)  shift(in, in.dims(0)/2, in.dims(1)/2)

template<typename T> AFAPI T mean(const array& in);
template <> float mean(const array& in);

int main(int argc, char **argv) {

	char *str3 = NULL;
	int num_of_scales = 24;
	int num_of_peaks = 3;
	float inc_amt = 0.0001;
	float *radius_deltas;
	array fixed_old;
	array moving_old;
	//const array& mem_result = &result_stack;
	if (argc < 3) {

		fixed_old = loadImage(ASSETS_DIR "/examples/fft_scale/fixed1.png");
		moving_old = loadImage(ASSETS_DIR "/examples/fft_scale/moving1.png");
		float j = 1 - num_of_scales*inc_amt;
		radius_deltas = new float[num_of_scales * 2 + 1];
		int num_radius_deltas = num_of_scales * 2 + 1;
		for (int i = 0; i < num_radius_deltas; i++) {
			radius_deltas[i] = j;
			j += inc_amt;
		}
		std::cout<<"Taking Default output directory\n";
		str3 = NULL;
	} else if (argc < 5){

		fixed_old = loadImage(argv[1]);
		moving_old = loadImage(argv[2]);
		float j = 1 - num_of_scales*inc_amt;
		radius_deltas = new float[num_of_scales * 2 + 1];
		int num_radius_deltas = num_of_scales * 2 + 1;
		for (int i = 0; i < num_radius_deltas; i++) {
			radius_deltas[i] = j;
			j += inc_amt;
		}
		std::cout<<"Taking Default output directory\n";
		str3 = NULL;

	} else if (argc < 6) {

		fixed_old = loadImage(argv[1]);
		moving_old = loadImage(argv[2]);
		std::string::size_type sz1;
		std::string::size_type sz2;
		num_of_scales = std::stoi(argv[3], &sz1);

		inc_amt = std::stof(argv[4], &sz2);
		float j = 1 - num_of_scales*inc_amt;
		radius_deltas = new float[num_of_scales * 2 + 1];
		for (int i = 0; i < num_of_scales * 2 +1; i++) {
			radius_deltas[i] = j;
			j += inc_amt;
		}

		std::cout<<"Taking Default output directory\n";
		str3 = NULL;


	} else {


		fixed_old = loadImage(argv[1]);
		moving_old = loadImage(argv[2]);

		std::string::size_type sz1;
		std::string::size_type sz2;
		num_of_scales = std::stoi(argv[3], &sz1);

		inc_amt = std::stof(argv[4], &sz2);
		float j = 1 - num_of_scales*inc_amt;
		radius_deltas = new float[num_of_scales * 2 + 1];
		for (int i = 0; i < num_of_scales * 2 + 1; i++) {
			radius_deltas[i] = j;
			j += inc_amt;
		}

		str3 = argv[5];

	}
	float max_value_real = 0;
	float min_value = 0;
	double max_imag_real = 0;
	unsigned idx_max = 0;
	unsigned idx_min = 0;

	float max_value_fft = 0;
	unsigned idx_max_fft = 0;
	//max(&max_element_array2, &max_idx_array2, &result_stack, 2);
	//max(&max_element_array3, &max_idx_array3, &result_stack, 3);
	//af::print("Max_Element_Array", max_value_real);


	array fixed;
	array moving;

	//for (int i = 0; i < 61; i++) {
	//	radius_deltas[i] = j;
	//	++j;
	//}
	dim4 fix_dims = fixed_old.dims();
	dim4 moving_dims = moving_old.dims();

	float imgh = fix_dims[1];
	float imgw = fix_dims[0];

	float imgh_mov = moving_dims[1];
	float imgw_mov = moving_dims[0];

	//std::cout<<imgh;

	if(fix_dims[0] != moving_dims[0]) {

		printf("Sizes inconsistent");
		exit(1);

	}

	if (fix_dims[1] != moving_dims[1]) {

		printf("Sizes inconsisteint");
		exit(1);

	}

	//fixed_old = fixed_old / 255;
	//moving_old = moving_old / 255;




	//af::print("REsized\n", fixed_old);
	//std::cout<<imgw / imgh;
//	if(imgw > imgh) {
//		fixed = array(imgh, imgh);
//		fixed = resize(fixed_old, fix_dims[1], fix_dims[1]);
//		imgw = imgh;
//	} else if(imgh > imgw){
//		fixed = array(imgw, imgw);
//		fixed = resize(fixed_old, fix_dims[0], fix_dims[0]);
//		imgh = imgw;
//		//std::cout<<fixed.dims()<<'\n';
//		//std::cout<<imgh<<'\n';
//	} else{
		fixed = array(imgh, imgw);
		fixed = fixed_old;
//	}

//	if(imgw_mov > imgh_mov) {
//		moving = array(imgh_mov, imgh_mov);
//		moving = moving = resize(moving_old, moving_dims[1], moving_dims[1]);
//		imgw_mov = imgh_mov;
//
//		//std::cout<<moving_dims[0]<<moving_dims[1];
//	} else if(imgh_mov > imgw_mov) {
//		moving = array(imgw_mov, imgw_mov);
//		moving = resize(moving_old, moving_dims[0], moving_dims[0]);
//		imgh_mov = imgw_mov;
//
//		//std::cout<<moving.dims()<<'\n';
//	} else {
		moving = array(imgh_mov, imgw_mov);
		moving = moving_old;
		//std::cout<<moving.dims()<<'\n';
//	}

		float mean_fixed = 0;
		
		mean_fixed = af::mean<float>(fixed);
		float mean_moving = af::mean<float>(moving);

	//std::cout<<"mean_fixed_dims:"<<mean_fixed<<'\n';
	fixed = fixed - mean_fixed;
	moving = moving - mean_moving;
//
	for (int d = 0; d<10; d++) {
		
		fixed(0, d) = 0;
		moving(0, d) = 0;
	
	}
//
	float stdev_fixed = stdev<float>(fixed);
	float stdev_moving = stdev<float>(moving);

	fixed = fixed / (stdev_fixed * 3);
	moving = moving / (stdev_moving * 3);
//

	af::max(&max_value_fft, &idx_max_fft, fixed);
	//std::cout<<max_value_fft<<'\n';

	array fixed_fft = fft2(fixed);
	fixed_fft(0, 0) = 0;
	array moving_fft = fft2(moving);
	moving_fft(0, 0) = 0;
	af::max(&max_value_fft, &idx_max_fft, fixed_fft);

	int num_radius_deltas = num_of_scales * 2 + 1;
	array result_stack(imgw, imgh, num_radius_deltas);

	float peaks[num_radius_deltas];
	float min_values[num_radius_deltas];
	for (int i = 0; i< num_radius_deltas; i++) {
		float rd = radius_deltas[i];
		array result;
		//std::cout<<scale_y<<'\n';
		if (rd < 1) {
			rd = 2 - rd;

			std::cout<<rd<<'\n';	
			float scale_y = rd;
			float scale_x = rd;

			float t_x = ceil((imgw + 1) / 2)  * (1 - scale_x);
			float t_y = ceil((imgh + 1) / 2)  * (1 - scale_y);


			float transformation_entries[] = {scale_x, 0.0, t_x, 0.0, scale_y, t_y};
			array transform_matrix(3, 2, transformation_entries);
			array moving_scaled = transform(moving, transform_matrix, 0, 0, AF_INTERP_BICUBIC_SPLINE, false);


			array moving_scaled_fft = fft2(moving_scaled);
			array conj_mov_scaled_fft = conjg(moving_scaled_fft);

			array result_fft = fixed_fft * conj_mov_scaled_fft; 
			array inv_fft = ifft2(result_fft);
			result = fftshift(abs(inv_fft));
			af::max(&max_value_real, &idx_max, result);
			af::min(&min_value, &idx_min, result);
			std::cout<<max_value_real<<'\n';
			std::cout<<"Index: "<<idx_max<<'\n';
			peaks[i] = max_value_real;
			min_values[i] = min_value;
			//std::cout<<result.dims(0)<<rd<<result.dims(1)<<'\n';
			result_stack(span,span,i) = result(span, span);
	} else if (rd > 1){
		float scale_y = rd;
		float scale_x = rd;
		std::cout<<rd<<'\n';
		float t_x = ceil((imgw + 1) / 2)  * (1 - scale_x);
		float t_y = ceil((imgh + 1) / 2)  * (1 - scale_y);
		float transformation_entries[] = {scale_x, 0.0, t_x, 0.0, scale_y, t_y};
		array transform_matrix(3, 2, transformation_entries);

		array fixed_scaled = transform(fixed, transform_matrix,0, 0,  AF_INTERP_BICUBIC_SPLINE, false);


		timer start_fft2 = timer::start();

		array fixed_scaled_fft = fft2(fixed_scaled);
		printf("FFT_Fixed: %g Micro Seconds\n", timer::stop(start_fft2) * 1e6);

		timer start_conjg = timer::start();

		array conj_mov_fft = conjg(moving_fft);
		printf("Conjg function: %g Micro Seconds\n", timer::stop(start_conjg) * 1e6);

		timer start_mult = timer::start();
		array result_fft = fixed_scaled_fft * conj_mov_fft;

		printf("Time_mult: %g Micro Seconds\n", timer::stop(start_mult) * 1e6);

		timer start_inv_fft = timer::start();
		array inv_fft = ifft2(result_fft);
		printf("Time_inv_fft: %g Micro Seconds\n", timer::stop(start_inv_fft) * 1e6);
		result = fftshift(abs(inv_fft));
		af::max(&max_value_real, &idx_max, result);
		af::min(&min_value, &idx_min, result);
		std::cout<<"Index: "<<idx_max<<'\n';

		//std::cout<<"str"<<'\n';
		peaks[i] = max_value_real;
		min_values[i] = min_value;
		result_stack(span, span,i) = result;
	}else {
	
	

		array conj_mov_fft = conjg(moving_fft);
		//printf("Conjg function: %g Micro Seconds\n", timer::stop(start_conjg) * 1e6);

		timer start_mult = timer::start();
		array result_fft = fixed_fft * conj_mov_fft;

		printf("Time_mult: %g Micro Seconds\n", timer::stop(start_mult) * 1e6);

		timer start_inv_fft = timer::start();
		array inv_fft = ifft2(result_fft);
		printf("Time_inv_fft: %g Micro Seconds\n", timer::stop(start_inv_fft) * 1e6);
		result = fftshift(abs(inv_fft));
		af::max(&max_value_real, &idx_max, result);
		af::min(&min_value, &idx_min, result);
		std::cout<<"Index: "<<idx_max<<'\n';

		//std::cout<<"str"<<'\n';
		peaks[i] = max_value_real;
		min_values[i] = min_value;
		result_stack(span, span,i) = result;

	}		
	//		

}
//max_value_real = af::max(result_stack);
//af_print(result_stack(0, 0, 0));
std::cout<<"Max Value: "<<max_value_real<<'\n';
af::min(&min_value, &idx_min, result_stack(span, span, span));
//result_stack = (result_stack - min_value) / (max_value_real - min_value);

result_stack = result_stack - min_value;
af::max(&max_value_real, &idx_max, result_stack(span, span, span));
std::cout<<"Max Index Flat: "<<idx_max<<'\n';

float max_final = 0.0;
int max_index = 0;
for (int u = 0; u <num_radius_deltas; u++ ){
	if (peaks[u] > max_final){
		max_final = peaks[u];
		max_index = u;
	}
}



for (int norm_i = 0; norm_i < num_radius_deltas; norm_i++){

	char str[200];
	if (str3 != NULL) {
		sprintf(str, "%simage%02d.png", str3, norm_i);
	} else {
		sprintf(str, "image%02d.png", norm_i);
	}
	array result1 = result_stack(span, span, norm_i);
	result1 = (result1 - min_values[norm_i])/ (max_value_real - min_values[norm_i]);
	//max(&max_value_real, &idx_max, result2);
	//std::cout<<max_value_real<<'\n';
	saveImage(str, result1);
}
//std::cout<<"Max_Final_peak: "<<max_final<<'\n';
//std::cout<<"Index in stack: "<<max_index<<'\n';

int resultDimY = result_stack.dims(0);
int resultDimX = result_stack.dims(1);
int resultDimZ = result_stack.dims(2);

int cX = ceil((resultDimX + 1) / 2.0);
int cY = ceil((resultDimY + 1) / 2.0);
int cZ = ceil((resultDimZ + 1) / 2.0);

array max_along_3;
array max_idx_3;
af::max(max_along_3, max_idx_3, result_stack(span, span, span), 2);
std::cout<<max_along_3.dims(0)<<'\n';
array maxfilted = maxfilt(max_along_3, 3, 3, AF_PAD_ZERO);
array eq_array_stack(imgw, imgh, num_radius_deltas);
for (int f = 0; f < num_radius_deltas; f++) {

	array eq_array;
	eq_array = operator==(result_stack(span, span, f), maxfilted);
	eq_array_stack(span, span, f) = eq_array;

}
array idx = where(eq_array_stack);
array sorted_stack;
array sorted_idx_stack;
sort(sorted_stack, sorted_idx_stack, result_stack(idx), 0, false);

array idx_sorted = idx(sorted_idx_stack);

array xs(idx_sorted.dims(0));
array ys(idx_sorted.dims(0));
array zs(idx_sorted.dims(0));
array resids(idx_sorted.dims(0));

//ind2sub
for (int j = 0; j< idx_sorted.dims(0); j++)	{
	//std::cout<<j<<'\n';
	zs(j) =  floor((idx_sorted(j) / (result_stack.dims(0) * result_stack.dims(1))));
	resids(j) = (idx_sorted(j) % (result_stack.dims(0) * result_stack.dims(1)));
	xs(j) = floor(resids(j) / result_stack.dims(0));
	ys(j) = (resids(j) % result_stack.dims(0));


}
//std::cout<<xs.dims(0)<<'\n';

//array peakLocs(num_of_peaks, 7);

		timer sub_pixel = timer::start();


for (int p = 0; p< num_of_peaks; p++){
//	std::cout<<p<<'\n';
	float arr[] = {xs(p).scalar<float>(), ys(p).scalar<float>(), zs(p).scalar<float>(), sorted_stack(p).scalar<float>()};
	array peakLocInit(1,4,arr);

//	std::cout<<p<<'\n'	;
	array maxx = peakLocInit(0);
	array maxy = peakLocInit(1);
	array maxz = peakLocInit(2);
	array maxj;

	array domainFull;
	array sliceFull1;
	array sliceFull;

	for (int d=1; d<4; d++){
		if(d == 1){
			//std::cout<<result_stack.dims(0)<<'\n';
			sliceFull1 = result_stack(maxy, span, maxz);
			sliceFull = array(result_stack.dims(1), 1);
			for (int slj = 0; slj < result_stack.dims(1); slj++) {
			
				sliceFull(slj) = sliceFull1(0, slj, 0);
			
			}
			array tempDomainFull = range(dim4(resultDimX));
			//std::cout<<"Am I here"<<'\n'<<tempDomainFull.dims(0)<<'\n';
			domainFull = tempDomainFull(span);
			domainFull = domainFull - cX;
			maxj = maxx;
		}
	else if(d == 2){
			sliceFull1 = result_stack(span, maxx, maxz);
			sliceFull = array(result_stack.dims(0), 1);
			for (int slj = 0; slj < result_stack.dims(0); slj++) {
			
				sliceFull(slj) = sliceFull1(slj, 0, 0);
			
			}
			array tempDomainFull = range(dim4(resultDimY));
			domainFull = tempDomainFull(span);
			domainFull = domainFull - cY;
			maxj = maxy;
	} else {
			sliceFull1 = result_stack(maxy, maxx, span);
			sliceFull = array(result_stack.dims(2), 1);
			for (int slj = 0; slj < result_stack.dims(2); slj++) {
			
				sliceFull(slj) = sliceFull1(0, 0, slj);
			
			}
			array tempDomainFull = range(dim4(num_radius_deltas));
			domainFull = tempDomainFull(span)- 1;
			maxj = maxz;
		}
	float minr;
	unsigned idx_doesnt_mat;
	af::min(&minr, &idx_doesnt_mat, sliceFull);
	array maxr = sliceFull(maxj);

	
	if(maxr.scalar<float>() != minr){
		sliceFull = (sliceFull - minr) / (maxr.scalar<float>() - minr);
	}
 	array sliceLo = sliceFull(seq(maxj.scalar<float>()));	
	array sliceHi = sliceFull(seq(maxj.scalar<float>() - 1, end));
//	
	array slopesLo(sliceLo.dims(0) - 1, sliceLo.dims(1));
	array slopesHi(sliceHi.dims(0) - 1, sliceHi.dims(1));
	for(int gdx = 0; gdx<(sliceLo.dims(0) - 1); gdx++) {
		slopesLo(gdx) = sliceLo(sliceLo.dims(0) - gdx - 1)  - sliceLo(sliceLo.dims(0) - gdx - 2); 
	}
	
	array indx_array_lo = where(operator<=(slopesLo, 0));
	array first_indx = indx_array_lo(0, 0);
	array strt;
	array stop;
	if(!first_indx.isempty()){
		strt = (maxj+1) - first_indx;
	} else {
		
		float arr1[] = {0};
		strt = array(1,1,arr1);
	}

	for(int gdx = 0; gdx<sliceHi.dims(0) - 1; gdx++) {
		slopesHi(gdx) = sliceHi(gdx)  - sliceHi(gdx + 1); 
	}

	array indx_array_hi = where(operator<=(slopesHi, 0));
	first_indx = indx_array_hi(0, 0);
	//float f_id = first_indx.scalar<float>();
	if (!first_indx.isempty()){
		stop = (maxj-1) + first_indx;
	}else {
		
		float arr1[] = {(float)sliceFull.dims(0)};
		stop = array(1,1,arr1);
	}

	array slice = sliceFull(seq(strt.scalar<float>(),stop.scalar<float>()));

}
}

		printf("Sub_Pixel: %g Micro Seconds\n", timer::stop(sub_pixel) * 1e6);
}

