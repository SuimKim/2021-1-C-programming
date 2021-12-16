#include <stdio.h>     
#include <string.h>
//=====================================================================================
void Eliminate(char *str, char e){
    for (; *str != '\0'; str++){  //종료 문자를 만날 때까지 반복  
		if(*str==e){              //문자열이 e와 같으면  
			strcpy(str,str+1);    //다음 문자열을 해당 문자열로 복사하여 한 칸씩 이동 
		}
    }
}
//=====================================================================================
void EliminateEnter(char *str){  
	for(; *str != '\0'; str++){  //종료 문자를 만날 때까지 반복  
		if(*str =='\n')          //str이 줄바꿈이면  
			*str=' ';            //공백으로 대체  
	}
}
//=====================================================================================
int main(void){
	char buffer[10000];  //파일에서 문자열을 읽어 저장할 임시 공간
	
    FILE *source = fopen("source.txt", "r");         
    FILE *filtering = fopen("filtering.txt", "w");    
    
    if(source == NULL){
    	printf("source.txt 파일 열기에 실패했습니다.\n");
    	return 2;
	}
	if(filtering == NULL){
    	printf("filtering.txt 파일 열기에 실패했습니다.\n");
    	return 2;
	}
	//----------------------------------------------------------------------------------
	while(fgets(buffer,sizeof(buffer),source)){  //fgets는 한 줄씩 읽는 함수이므로 while 반복문 사용  
		strlwr(buffer);                          //소문자로 바꿈  
		Eliminate(buffer,'.');                   //.문자 삭제  
		Eliminate(buffer,',');                   //,문자 삭제  
	    EliminateEnter(buffer);                  //Enter 삭제  
		fprintf(filtering,"%s",buffer);          //buffer에 저장된 내용을 filtering.txt에 저장 
	}
	
	fclose(source);
    fclose(filtering);

    
    
    printf("문자열 중간 정리 완료\n");
	return 0; 
}
