

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 32768


void redHeadError(int head_pos);

//add comments megvaltoztatom ezt a cucost
int main(){

    int head_pos = 0;
    int loop_counter = 0;

    signed  char memory[32768] = {0};
    signed  char char_current_input;
    signed  char programkod[] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
        //while (scanf("%c", &current_input) == 1 && current_input != -1){
            //i < sizeof(programkod) / sizeof(char) - 1
    for (int i = 0; programkod[i] !='\0' ; i++){
        redHeadError(head_pos);
        //printf("%c\n", programkod[i]);
        //if (programkod[i] ='\0') programkod[i] = -1 ;

        switch (programkod[i])
        {
        case '<':
            head_pos = --head_pos;
            break;
        case '>':

            head_pos = ++head_pos;
            break;
        case '+':
            memory[head_pos] = ++memory[head_pos];
            break;
        case '-':
            memory[head_pos] = --memory[head_pos];
            break;
        case '.':
            if (memory[head_pos] >= '1' && memory[head_pos] <= '9') 
                printf("%d", memory[head_pos]); 
            else
                printf("%c", memory[head_pos]);
            break;
        case ',':
            scanf("%d", &memory[head_pos]);
            //memory[head_pos] = -1;//
            break;
        case '[':
            
            if (memory[head_pos] > 0){
                loop_counter++;
            } else {
                while (programkod[i] != ']'){
                    i++;
                }
            }
            break;
        case ']':
            if (loop_counter != 0){
                while (loop_counter != 0){
                    
                    if (programkod[i] == '['){
                        loop_counter--;
                        i--;
                    } else i--;
                }
            }
            break;
        default:
            break;
        }
        //printf("i:%d\nc:%c\nhead:%d\nval:%d\nl%d\n\n", i, programkod[i], head_pos, memory[head_pos],loop_counter);
    }
    //printf("%d", memory[1]);
    return 0;
}

// ERROR
void redHeadError(int head_pos){
    if (head_pos > MEMORY_SIZE - 1) {
        printf("Head Position Error on the Right");
        exit(-1);
    } else if (head_pos < 0) {
        printf("Head Position Error to the left");
        exit(-1);
    }
}
