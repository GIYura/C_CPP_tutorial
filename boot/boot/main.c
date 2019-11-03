#include <stdio.h>
#include <stdbool.h>

#define BUFF_SIZE 10

typedef enum{
	UP 		= 0,
	DOWN 	= 1,
	RIGHT 	= 2,
	LEFT 	= 3,
	COMMAND_NUM
}command_t;

void up(void){
	printf("Up\r\n");
}

void down(void){
	printf("Down\r\n");
}

void right(void){
	printf("Rigth\r\n");
}

void left(void){
	printf("Left\r\n");
}

typedef struct{
	int cmd;
	int responce[100];
	void (*f)(void);
}cmd_t;

bool transfer(cmd_t* cmd);
bool comm(command_t cmd, int* resp, void(*fp)(void));
int responce[100];

int add_odd(int* value, int len);
int add_even(int* value, int len);
int add_all(int* value, int len);

int buff[BUFF_SIZE] = { 0 };
bool send(command_t cmd);
typedef int(*callback)(int* value, int len);
bool receive(int* buff, int length, callback cb);

//
int main(int argc, char **argv)
{
	cmd_t cmd;
	bool res = false;
	printf("Result: %d\r\n", res);
	
	cmd.f = up;
	res = transfer(&cmd);
	
	cmd.f = down;
	res = transfer(&cmd);
	
	cmd.f = right;
	res = transfer(&cmd);
	
	cmd.f = left;
	res = transfer(&cmd);
	
	printf("------------------------\r\n");
	
	comm(UP, responce, up);
	comm(DOWN, responce, down);
	comm(RIGHT, responce, right);
	comm(LEFT, responce, left);
	
	printf("------------------------\r\n");
	
	printf("Add odd is working: ");
	receive(buff, BUFF_SIZE, add_odd);
	
	printf("Add even is working: ");
	receive(buff, BUFF_SIZE, add_even);
	
	printf("Add all is working: ");
	receive(buff, BUFF_SIZE, add_all);

	return 0;
}

bool transfer(cmd_t* cmd){
	cmd->f();
	return true;
}

bool comm(command_t cmd, int* resp, void(*fp)(void)){
	if(cmd < COMMAND_NUM){
		(*fp)();
	}
	return true;
}

bool send(command_t cmd){
	if(cmd < COMMAND_NUM){
		printf("Command sending...\r\n");
	}
	return true;
}

bool receive(int* buff, int length, callback cb){
	int res = 0;
	for(int i = 0; i < length; i++){
		buff[i] = i;
		printf("%d ", buff[i]);
	}
	
	res = (*cb)(buff, length);
	
	printf("\r\nResult: %d ", res);
	
	printf("\r\n------------------------\r\n");
	return true;
}

int add_odd(int* value, int len){
	int summ = 0;
	if(value[0] == 0 && value[len - 1] == 9){
		for(int i = 0; i < len; i++){
			if(value[i] % 2 != 0){
				summ += value[i];
			}
		}
	}
	return summ;
}

int add_even(int* value, int len){
	int summ = 0;
	
	if(value[0] == 0 && value[len - 1] == 9){
		for(int i = 0; i < len; i++){
			if(value[i] % 2 == 0){
				summ += value[i];
			}
		}
	}
	return summ;
}

int add_all(int* value, int len){
	int summ = 0;
	if(value[0] == 0 && value[len - 1] == 9){
		for(int i = 0; i < len; i++){
			summ += value[i];
		}
	}
	return summ;
}