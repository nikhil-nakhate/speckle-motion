#include <arrayfire.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace af;

#define fftshift(in)  shift(in, in.dims(0)/2, in.dims(1)/2)

int main(int argc, char **argv) {

	char *str3 = NULL;
	int num_of_scales = 30;
	float inc_amt = 0.01;
	int *radius_deltas;
	array fixed_old;
	array moving_old;
	//const array& mem_result = &result_stack;
	if (argc < 3) {
	
		fixed_old = loadImage(ASSETS_DIR "/examples/fft_scale/fixed1.pgm");
		moving_old = loadImage(ASSETS_DIR "/examples/fft_scale/moving1.pgm");
		int j = 1 - num_of_scales*inc_amt;
		radius_deltas = new int[num_of_scales * 2 + 1];
		for (int i = 0; i < 61; i++) {
			radius_deltas[i] = j;
			int j = 1 - num_of_scales*inc_amt;
		}
		std::cout<<"Taking Default output directory\n";
		str3 = NULL;
	} else if (argc < 5){

		fixed_old = loadImage(argv[1]);
		moving_old = loadImage(argv[2]);
		int j = 1 - num_of_scales*inc_amt;
		radius_deltas = new int[num_of_scales * 2 + 1];
		for (int i = 0; i < 61; i++) {
			radius_deltas[i] = j;
			int j = 1 - num_of_scales*inc_amt;
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
		int j = 1 - num_of_scales*inc_amt;
		radius_deltas = new int[num_of_scales * 2 + 1];
		for (int i = 0; i < num_of_scales; i++) {
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
		int j = 1 - num_of_scales*inc_amt;
		radius_deltas = new int[num_of_scales * 2 + 1];
		for (int i = 0; i < num_of_scales; i++) {
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

	fixed_old = fixed_old / 255;
	moving_old = moving_old / 255;

	
	//af::print("REsized\n", fixed_old);
	//std::cout<<imgw / imgh;
	if(imgw > imgh) {
		fixed = array(imgh, imgh);
		fixed = resize(fixed_old, fix_dims[1], fix_dims[1]);
		imgw = imgh;
	} else if(imgh > imgw){
		fixed = array(imgw, imgw);
		fixed = resize(fixed_old, fix_dims[0], fix_dims[0]);
		imgh = imgw;
		//std::cout<<fixed.dims()<<'\n';
		//std::cout<<imgh<<'\n';
	} else{
		fixed = array(imgh, imgw);
		fixed = fixed_old;
	}

	if(imgw_mov > imgh_mov) {
		moving = array(imgh_mov, imgh_mov);
		moving = moving = resize(moving_old, moving_dims[1], moving_dims[1]);
		imgw_mov = imgh_mov;

		//std::cout<<moving_dims[0]<<moving_dims[1];
	} else if(imgh_mov > imgw_mov) {
		moving = array(imgw_mov, imgw_mov);
		moving = resize(moving_old, moving_dims[0], moving_dims[0]);
		imgh_mov = imgw_mov;

		//std::cout<<moving.dims()<<'\n';
	} else {
		moving = array(imgh_mov, imgw_mov);
		moving = moving_old;
		//std::cout<<moving.dims()<<'\n';
	}

	af::max(&max_value_fft, &idx_max_fft, fixed);
	//std::cout<<max_value_fft<<'\n';

	array fixed_fft = fft2(fixed);
	array moving_fft = fft2(moving);

	af::max(&max_value_fft, &idx_max_fft, fixed_fft);

	int num_radius_deltas = num_of_scales * 2 + 1;
	array result_stack(imgw, imgh, 61);

	float peaks[61];
	for (int i = 0; i< num_radius_deltas; i++) {
		int rd = radius_deltas[i];
		array result;
		if(i < num_of_scales) {
		
			float new_imgh = imgh - (rd * 2);
			float new_imgw = imgw - (rd * 2);

			//std::cout<<new_imgw<<'\n';
			float scale_y = new_imgh / imgh;
			float scale_x = new_imgw / imgw;

			//std::cout<<scale_y<<'\n';

			float t_x = ceil((imgw + 1) / 2)  * (1 - (new_imgw / imgw));
			float t_y = ceil((imgh + 1) / 2)  * (1 - (new_imgh / imgh));

			float transformation_entries[] = {scale_x, 0.0, t_x, 0.0, scale_y, t_y};
			array transform_matrix(3, 2, transformation_entries);

			array moving_scaled = transform(moving, transform_matrix, 0, 0,  AF_INTERP_NEAREST, false);


			array moving_scaled_fft = fft2(moving_scaled);
			array conj_mov_scaled_fft = conjg(moving_scaled_fft);
			
			array result_fft = fixed_fft * conj_mov_scaled_fft; 

			array inv_fft = ifft2(result_fft);
			result = fftshift(abs(inv_fft));
			af::max(&max_value_real, &idx_max, result);
			af::min(&min_value, &idx_min, result);
			//std::cout<<max_value_real<<'\n';
			std::cout<<"Index: "<<idx_max<<'\n';
			peaks[i] = max_value_real;
			result = (result - min_value) / (max_value_real - min_value);
			char str[200];
			if (str3 != NULL) {
				sprintf(str, "%simage%02d.pgm", str3, i);
			} else {
				sprintf(str, "image%02d.pgm", i);
			}

			saveImage(str, result);
			//std::cout<<result.dims(0)<<rd<<result.dims(1)<<'\n';
			result_stack(span,span,i) = result;
			//std::cout<<moving_scaled_fft.dims(0)<<"hel"<<moving_scaled_fft.dims(1)<<'\n';
		} else if (i > num_of_scales) {
		
			float new_imgh = imgh + (rd*2);
			float new_imgw = imgw + (rd*2);

			float scale_y = new_imgh / imgh;
			float scale_x = new_imgw / imgw;

			float t_x = ceil((imgw + 1) / 2) * (1 - scale_x);
			float t_y = ceil((imgh + 1) / 2) * (1 - scale_y);

			float transformation_entries[] = {scale_x, 0.0, t_x, 0.0, scale_y, t_y};
			array transform_matrix(3, 2, transformation_entries);

			array fixed_scaled = transform(fixed, transform_matrix,0, 0,  AF_INTERP_NEAREST, false);
			

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
			result = (result - min_value) / (max_value_real - min_value);
			char str[200];
			//sprintf(str, "%simage%02d.pgm", str3, i);
			if (str3 != NULL) {
				sprintf(str, "%simage%02d.pgm", str3, i);
			} else {
				sprintf(str, "image%02d.pgm", i);
			}
			saveImage(str, result);
			result_stack(span, span,i) = result;

			//std::cout<<result.dims(0)<<"hasdfasdf"<<result.dims(1)<<'\n';
		} else {
			array conj_mov_fft = conjg(moving_fft);	
			
			array result_fft = fixed_fft * conj_mov_fft;
			
			array inv_fft = ifft2(result_fft);
			result = fftshift(abs(inv_fft));
			af::max(&max_value_real, &idx_max, result);
			af::min(&min_value, &idx_min, result);
			//std::cout<<"Peak Value at 30: "<<max_value_real<<'\n';
			std::cout<<"Index: "<<idx_max<<'\n';
			peaks[i] = max_value_real;
			result = (result - min_value) / (max_value_real - min_value);
			char str[200];
			//sprintf(str, "%simage%02d.pgm", str3, i);
			saveImage(str, result);
			if (str3 != NULL) {
				sprintf(str, "%simage%02d.pgm", str3, i);
			} else {
				sprintf(str, "image%02d.pgm", i);
			}
			//char key_str[20];
			//sprintf(key_str, "A%02d", i);
			//saveArray(key_str, result, str);
			result_stack(span, span, i) = result;

			//std::cout<<"Index of Max"<<idx_max<<'\n';
			//std::cout<<result.dims(0)<<"this is zero"<<result.dims(1)<<'\n';
		}


	//const array& mem_result = &result_stack;

	//double *max_value_real;
	//double *max_imag_real;
	//unsigned *idx;

	//af::max(max_value_real, idx, result_stack);
	//max(&max_element_array2, &max_idx_array2, &result_stack, 2);
	//max(&max_element_array3, &max_idx_array3, &result_stack, 3);
	//af::print("Max_Element_Array", max_value_real);
	//std::cout<<max_value_real;
	}
	af::max(&max_value_real, &idx_max, result_stack);
	af::min(&min_value, &idx_min, result_stack);
	//result_stack = (result_stack - min_value) / (max_value_real - min_value);
	std::cout<<"Max Index Flat: "<<idx_max<<'\n';
	std::cout<<"result stack dims"<<result_stack.dims()<<'\n';
	
	float max_final = 0.0;
	int max_index = 0;
	for (int u = 0; u <61; u++ ){
		if (peaks[u] > max_final){
			max_final = peaks[u];
			max_index = u;
		}
	}
	std::cout<<"Max_Final_peak: "<<max_final<<'\n';
	std::cout<<"Index in stack: "<<max_index<<'\n';
	//std::cout<<max_value_real<<'\n';
	//std::cout<<idx_max<<'\n';

	//char str2[200];
	//for (int j = 0; j<60; j++) {
	//	sprintf(str2, "image%02d.pgm", j);
	//	saveImage(str2, result_stack(span, span, j));
	//}

}

