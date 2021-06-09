//g++ -O2 mergesort.cpp -o mergesort && ./mergesort
#include <stdio.h>
#include <random>
#include <chrono>

void merge_sort_small_first(unsigned int* _start_arr, unsigned int _lenght){
	unsigned int k = 1;
	unsigned int array2[_lenght];
	unsigned int* array[2] = {_start_arr, array2};
	unsigned int* pointer = array2;
	unsigned int* p1 = array[0];
	unsigned int* p2 = array[0] + k;
	unsigned int* position = p2;
	unsigned int count = 1;
	unsigned int* limit = _start_arr + _lenght;
	unsigned int* limit2 = array2 + _lenght;
	
	while(k < _lenght){
		for(; p2 < limit;pointer++){
			if(*p1 < *p2){
				*pointer = *p1;
				p1++;
				if(p1 >= position){
					if(position + k < limit){
						while(p2 < position + k){
							pointer++;
							*pointer = *p2;
							p2++;
						}
					}
					else{
						while(p2 < limit){
							pointer++;
							*pointer = *p2;
							p2++;
						}
					}
					p1 = position + k;
					p2 = p1 + k;
					position = p2;
				}
			}
			else{
				*pointer = *p2;
				p2++;
				if(p2 >= position + k){
					while(p1 < position){
						pointer++;
						*pointer = *p1;
						p1++;
					}
					p1 = position + k;
					p2 = p1 + k;
					position = p2;
				}
			}
		}
		while(pointer < limit2){
			*pointer = *p1;
			p1++;
			pointer++;
		}
		k = k*2;
		p1 = array[count];
		p2 = array[count] + k;
		position = p2;
		limit = array[count] + _lenght;
		count = (count + 1) % 2;
		limit2 = array[count] + _lenght;
		pointer = array[count];
	}
	if(count != 1){
		for(int i = 0;i < _lenght; i++ ){
			array[0][i] = array[1][i];
		}
	}
}

void merge_sort_big_first(unsigned int* _start_arr, unsigned int _lenght){
	unsigned int k = 1;
	unsigned int array2[_lenght];
	unsigned int* array[2] = {_start_arr, array2};
	unsigned int* pointer = array2;
	unsigned int* p1 = array[0];
	unsigned int* p2 = array[0] + k;
	unsigned int* position = p2;
	unsigned int count = 1;
	unsigned int* limit = _start_arr + _lenght;
	unsigned int* limit2 = array2 + _lenght;
	
	while(k < _lenght){
		for(; p2 < limit;pointer++){
			if(*p1 > *p2){
				*pointer = *p1;
				p1++;
				if(p1 >= position){
					if(position + k < limit){
						while(p2 < position + k){
							pointer++;
							*pointer = *p2;
							p2++;
						}
					}
					else{
						while(p2 < limit){
							pointer++;
							*pointer = *p2;
							p2++;
						}
					}
					p1 = position + k;
					p2 = p1 + k;
					position = p2;
				}
			}
			else{
				*pointer = *p2;
				p2++;
				if(p2 >= position + k){
					while(p1 < position){
						pointer++;
						*pointer = *p1;
						p1++;
					}
					p1 = position + k;
					p2 = p1 + k;
					position = p2;
				}
			}
		}
		while(pointer < limit2){
			*pointer = *p1;
			p1++;
			pointer++;
		}
		k = k*2;
		p1 = array[count];
		p2 = array[count] + k;
		position = p2;
		limit = array[count] + _lenght;
		count = (count + 1) % 2;
		limit2 = array[count] + _lenght;
		pointer = array[count];
	}
	if(count != 1){
		for(int i = 0;i < _lenght; i++ ){
			array[0][i] = array[1][i];
		}
	}
}

const unsigned int LENGHT = 40;
unsigned int array1[LENGHT];

int main(int argc, char *argv[]){
	//Filling array with rand values
	for(int i = 0; i < LENGHT;i++){
		array1[i] = rand() % 10000;
		printf("%d,",array1[i]);
	}
	printf("\n\n");
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	start = std::chrono::high_resolution_clock::now();
	merge_sort_big_first(array1, LENGHT);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	printf("time: %lu nanoseconds\n\n",duration.count());

	for(int i = 0; i < LENGHT;i++){
		printf("%d,",array1[i]);
	}

	return 0;
}
