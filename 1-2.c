#include <stdio.h>     
#include <string.h>
//===================================================================================================
void EliminateSpace(char *str){                  //중복된 스페이스를 삭제하는 함수  
    for (; *str != '\0'; str++){                 //종료 문자를 만날 때까지 반복  
		if((*str == ' ') && (*(str+1) == ' ')){  //문자열이 공백이면서 다음 문자열이 공백이면  
			strcpy(str, str+1);                  //다음 문자열을 해당 문자열로 복사하여 한 칸씩 이동 
		}
    }
}
//====================================================================================================
int main(void){
	char buffer[10000];  //파일에서 문자열을 읽어 저장할 임시 공간
	
	FILE *ing = fopen("filtering.txt", "r");    
    FILE *ed = fopen("filtered.txt", "w");   
    
    if(ing == NULL || ed == NULL){
    	printf("파일 열기에 실패했습니다.\n");
    	return 2;
	}
	
	fgets(buffer,sizeof(buffer),ing);   //Enter를 전 단계에서 삭제했음으로 반복문 사용하지 않아도 됨 
	EliminateSpace(buffer);             //중복된 Space 삭제  

    fprintf(ed,"%s",buffer);            //buffer에 저장된 내용을 filtered.txt에 저장  
    
    fclose(ing);
    fclose(ed);
    
    printf("문자열 최종 정리 완료\n");
    return 0;
}


