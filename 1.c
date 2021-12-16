#include <stdio.h>     
#include <string.h>
//=====================================================================================
void Eliminate(char *str, char e){
    for (; *str != '\0'; str++){  //���� ���ڸ� ���� ������ �ݺ�  
		if(*str==e){              //���ڿ��� e�� ������  
			strcpy(str,str+1);    //���� ���ڿ��� �ش� ���ڿ��� �����Ͽ� �� ĭ�� �̵� 
		}
    }
}
//=====================================================================================
void EliminateEnter(char *str){  
	for(; *str != '\0'; str++){  //���� ���ڸ� ���� ������ �ݺ�  
		if(*str =='\n')          //str�� �ٹٲ��̸�  
			*str=' ';            //�������� ��ü  
	}
}
//=====================================================================================
int main(void){
	char buffer[10000];  //���Ͽ��� ���ڿ��� �о� ������ �ӽ� ����
	
    FILE *source = fopen("source.txt", "r");         
    FILE *filtering = fopen("filtering.txt", "w");    
    
    if(source == NULL){
    	printf("source.txt ���� ���⿡ �����߽��ϴ�.\n");
    	return 2;
	}
	if(filtering == NULL){
    	printf("filtering.txt ���� ���⿡ �����߽��ϴ�.\n");
    	return 2;
	}
	//----------------------------------------------------------------------------------
	while(fgets(buffer,sizeof(buffer),source)){  //fgets�� �� �پ� �д� �Լ��̹Ƿ� while �ݺ��� ���  
		strlwr(buffer);                          //�ҹ��ڷ� �ٲ�  
		Eliminate(buffer,'.');                   //.���� ����  
		Eliminate(buffer,',');                   //,���� ����  
	    EliminateEnter(buffer);                  //Enter ����  
		fprintf(filtering,"%s",buffer);          //buffer�� ����� ������ filtering.txt�� ���� 
	}
	
	fclose(source);
    fclose(filtering);

    
    
    printf("���ڿ� �߰� ���� �Ϸ�\n");
	return 0; 
}
