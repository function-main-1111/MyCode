//�̤U�����X������
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char boolFunc[100];
int strEndId;//ID�N�����index
int a, b, c, d;

//�C�X�B�z�B�J�A�Ψ�debug
void DebugPrint(int leftId, int rightId){
  for(int i=leftId;i<=rightId;i++){
    printf("%c", boolFunc[i]);
  }
  printf("\n");
}

//id�O�_�����Ӧr��
bool BFuncIdIsChar(int id,char ch){
  return boolFunc[id]==ch;
}

//��J�k����id�䥪�A��id
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

//�Τ_���j�p�⪺��ơA�O�o�{�����֤߳���
int F_Cal(int leftId, int rightId){
  
  //DebugPrint(leftId,rightId);
  
  //�J���ӥN�ƪ����^�ǭ�
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
  
  //�Ϥ��U�@��OR�e��A���O�p��
  for(int i=leftId;i<=rightId;i++){
    //�J��A�����L
    if(BFuncIdIsChar(i, '('))
      i=GetBracketEndId(i);
    if(BFuncIdIsChar(i, '+'))
      return F_Cal(leftId, i-1) || F_Cal(i+1, rightId);
    //
  }
  
  //�Ϥ�����And
  for(int i=leftId;i<=rightId;i++){
    //�J��A�����L
    if(BFuncIdIsChar(i, '('))
      i=GetBracketEndId(i);
    //�LNOT
    if(i+1<=rightId && !BFuncIdIsChar(i+1, '\'') )
      return F_Cal(leftId, i) && F_Cal(i+1, rightId);
    //��NOT
    if(i+2<=rightId && BFuncIdIsChar(i+1, '\'') )
      return F_Cal(leftId, i+1) && F_Cal(i+2, rightId);
    //
  }
  
  //�B�z�A����
  if(BFuncIdIsChar(leftId, '(')){
    int i=GetBracketEndId(leftId);
      //��NOT
      if(i+1<=rightId && BFuncIdIsChar(i+1, '\''))
        return !F_Cal(leftId+1, rightId-2);
      //�LNOT
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
    //�u�Ȫ�
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
    //�d�չ�
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
//����G
//
//�|�hXOR �A�����i�}
//((A'B+AB')C'+(A'B+AB')'C)D'+((A'B+AB')C'+(A'B+AB')'C)'D
//����XOR �A���i�}
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
