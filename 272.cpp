#include<stdio.h>

int main(){
  char c;
  bool isOpen = false;

  while((c=getchar()) != EOF){
    if(c=='"'){
      if(!isOpen){
        printf("``");
        isOpen = true;
      }else{
        printf("''");
        isOpen = false;
      }
    }else{
      putchar(c);
    }
  }
}
