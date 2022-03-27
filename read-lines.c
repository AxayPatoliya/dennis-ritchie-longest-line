// find the total number of lines in a file
// then create an int array of the size of line_nums
// assign a value to an array on the basis of individual line length(i.e. line_1_len = 10 then arr[0]=10)
// find the line from a file whose length is maximum(on the basis of index of biggest number in an array)


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *file;
    char c, d;
    int total_char_count=0;
    int line_nums = 0;
    int sap_line_count=0;
    file = fopen("sample.txt", "r");

    if(file!=NULL){
        int total_char_count=0;
        // get the total number of lines in a file
        while(c!=EOF){
            // counting total number of character in a file
            if(c!='\n'){
                total_char_count++;
            }

            c = fgetc(file);
            if(c==EOF || c=='\n'){
                ++line_nums;
            }
        }
        printf("total char count: %d\n", total_char_count);

        fseek(file, 0, SEEK_SET); //resetting the file reading pointer to starting

        int i = 0;
        
        int *line_lengths = NULL; //create an integer pointer with value NULL
        line_lengths = (int*)calloc(line_nums, sizeof(int)); //allocate memory of the size of line_nums
        // for(int i=0; i<line_nums; ++i){
        //     line_lengths = calloc(1, sizeof(int)); //assigning value to the pointer same as the size of one integer(4 bytes)
        //     line_lengths++;
        // }
        

        while(d!=EOF){
            d = fgetc(file);
            if(d==EOF || d=='\n'){
                line_lengths[i] = sap_line_count;
                i++;
                sap_line_count = 0;
            } else{
                ++sap_line_count;
            }
        }
        
        int max = 0;
        int max_index = 0;
        for(int i=0; i<line_nums; i++){
            if(line_lengths[i]>max){
                max = line_lengths[i];
                max_index = i;
            }
        }
        printf("line nums(total number of lines in a file) = %d\n", line_nums);
        printf("max in array(length of longest line) = %d\n", max);
        printf("index of max in array(line number of maximum line) = %d\n", max_index+1);


        int count = 0;
        // char longest[max+1];
        char *longest = NULL; //create a character pointer with value NULL
        longest = (char*)calloc(max+1, sizeof(char)); //creating character array of size max+1 dynamically
        // printf("longest line = %d", max+1);
        fseek(file, 0, SEEK_SET); //resetting the file reading pointer to starting
            while (fgets(longest, max+1, file) != NULL){ /* read a line */
                if (count == max_index){   
                    printf("\nlongest line:\n%s\n", longest);
                    fclose(file);

                    // free the memory blocks
                    free(line_lengths);
                    free(longest);
                }   
                else{   
                    count++;
                }   
            } 
    } else{
        printf("file is empty\n");
    }


    return 0;
}