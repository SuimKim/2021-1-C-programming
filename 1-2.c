#include <stdio.h>     
#include <string.h>
//===================================================================================================
void EliminateSpace(char *str){                  //�ߺ��� �����̽��� �����ϴ� �Լ�  
    for (; *str != '\0'; str++){                 //���� ���ڸ� ���� ������ �ݺ�  
		if((*str == ' ') && (*(str+1) == ' ')){  //���ڿ��� �����̸鼭 ���� ���ڿ��� �����̸�  
			strcpy(str, str+1);                  //���� ���ڿ��� �ش� ���ڿ��� �����Ͽ� �� ĭ�� �̵� 
		}
    }
}
//====================================================================================================
int main(void){
	char buffer[10000];  //���Ͽ��� ���ڿ��� �о� ������ �ӽ� ����
	
	FILE *ing = fopen("filtering.txt", "r");    
    FILE *ed = fopen("filtered.txt", "w");   
    
    if(ing == NULL || ed == NULL){
    	printf("���� ���⿡ �����߽��ϴ�.\n");
    	return 2;
	}
	
	fgets(buffer,sizeof(buffer),ing);   //Enter�� �� �ܰ迡�� ������������ �ݺ��� ������� �ʾƵ� �� 
	EliminateSpace(buffer);             //�ߺ��� Space ����  

    fprintf(ed,"%s",buffer);            //buffer�� ����� ������ filtered.txt�� ����  
    
    fclose(ing);
    fclose(ed);
    
    printf("���ڿ� ���� ���� �Ϸ�\n");
    return 0;
}


