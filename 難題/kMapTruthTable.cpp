//最下面有幾筆測資
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char boolFunc[100];
int strEndId;//ID代表索引index
int a, b, c, d;

//列出處理步驟，用來debug
void DebugPrint(int leftId, int rightId){
  for(int i=leftId;i<=rightId;i++){
    printf("%c", boolFunc[i]);
  }
  printf("\n");
}

//id是否對應該字元
bool BFuncIdIsChar(int id,char ch){
  return boolFunc[id]==ch;
}

//輸入右掛號id找左括號id
int GetBracketEndId(int bracketHeadId ){
  int cnt=1;
  for(int i=bracketHeadId+1;i<=strEndId;i++){
    if(BFuncIdIsChar(i, '('))
      cnt++;
    if(BFuncIdIsChar(i, ')'))
      cnt--;
    if(cnt==0)
      return i;
  }
}

//用于遞迴計算的函數，是這程式的核心部分
int F_Cal(int leftId, int rightId){
  
  //DebugPrint(leftId,rightId);
  
  //遇到單個代數直接回傳值
  if(leftId==rightId){
    if(BFuncIdIsChar(leftId, 'A'))
      return a;
    else if(BFuncIdIsChar(leftId, 'B'))
      return b;
    else if(BFuncIdIsChar(leftId, 'C'))
      return c;
    else if(BFuncIdIsChar(leftId, 'D'))
      return d;
    //
  }
  else if(leftId==rightId-1 && BFuncIdIsChar(rightId, '\'')){
    if(BFuncIdIsChar(leftId, 'A'))
      return !a;
    else if(BFuncIdIsChar(leftId, 'B'))
      return !b;
    else if(BFuncIdIsChar(leftId, 'C'))
      return !c;
    else if(BFuncIdIsChar(leftId, 'D'))
      return !d;
    //
  }
  
  //區分下一個OR前後，分別計算
  for(int i=leftId;i<=rightId;i++){
    //遇到括號跳過
    if(BFuncIdIsChar(i, '('))
      i=GetBracketEndId(i);
    if(BFuncIdIsChar(i, '+'))
      return F_Cal(leftId, i-1) || F_Cal(i+1, rightId);
    //
  }
  
  //區分隱性And
  for(int i=leftId;i<=rightId;i++){
    //遇到括號跳過
    if(BFuncIdIsChar(i, '('))
      i=GetBracketEndId(i);
    //無NOT
    if(i+1<=rightId && !BFuncIdIsChar(i+1, '\'') )
      return F_Cal(leftId, i) && F_Cal(i+1, rightId);
    //有NOT
    if(i+2<=rightId && BFuncIdIsChar(i+1, '\'') )
      return F_Cal(leftId, i+1) && F_Cal(i+2, rightId);
    //
  }
  
  //處理括號內
  if(BFuncIdIsChar(leftId, '(')){
    int i=GetBracketEndId(leftId);
      //有NOT
      if(i+1<=rightId && BFuncIdIsChar(i+1, '\''))
        return !F_Cal(leftId+1, rightId-2);
      //無NOT
      if(BFuncIdIsChar(rightId, ')'))
        return F_Cal(leftId+1, rightId-1);
    //
  }
  
}

int main(){
  
  printf("enter -1 to end\n ");
  while(true){
    printf("enter bool function\n ");
    scanf("%99s", boolFunc);
    if(boolFunc[0]=='-' && boolFunc[1]=='1')
      break;
    strEndId=strlen(boolFunc)-1;
    
    int arr[16], ans;
    //真值表
    printf("\nA B C D | F\n");
    for(a=0;a<=1;a++){
      for(b=0;b<=1;b++){
        for(c=0;c<=1;c++){
          for(d=0;d<=1;d++){
            ans=F_Cal(0, strEndId);
            arr[a*8+b*4+c*2+d]=ans;
            printf("%d %d %d %d | %d\n",a,b,c,d,ans);
          }
        }
      }
    }
    //卡諾圖
    printf("\nAB/CD 00 01 11 10\n");
    printf("00    %d  %d  %d  %d \n",arr[0],arr[1],arr[3],arr[2]);
    printf("01    %d  %d  %d  %d \n",arr[4],arr[5],arr[7],arr[6]);
    printf("11    %d  %d  %d  %d \n",arr[12],arr[13],arr[15],arr[14]);
    printf("10    %d  %d  %d  %d \n",arr[8],arr[9],arr[11],arr[10]);
    printf("\n");
  }
  printf("Bye bye");
  
  return 0;
}
//測資：
//
//四層XOR 括號未展開
//((A'B+AB')C'+(A'B+AB')'C)D'+((A'B+AB')C'+(A'B+AB')'C)'D
//全部XOR 括號展開
//A'B'C'D+A'B'CD'+A'BC'D'+A'BCD+AB'C'D'+AB'CD+ABC'D+ABCD'
//NAND
//(ABCD)'
//NOR
//(A+B+C+D)'
//
//A+B'(C+D)'
//(A+B)(C'D)+A'(B+C)
//(A+B')'(C+D')+A'B'C
//(A+B+C)(A'B'+CD')'
//(A'B+AB')C'+(A'B+AB')'C
//((A'B+AB')C'+(A'B+AB')'C)D'+((A'B+AB')C'+D(A'B+AB')'C)'
