#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
typedef struct node{
	char id[20];
	char pw[20];
	char email[50];
	char write[3][1000];
	char title[3][20];
	char name[20];
	int brith;
	int code;
	int num;
	int wcode[3];
	int adwcode[3];
	struct node* link; 
}node; 
node *head=NULL;
char ADcode[20]={"asdasd"};
int menu(node *p);
node *sigh();
int overrap(char *id);
node* loginid();
void *print();
node *search();
node *chpw(node *p);
node *findid();
node *findpw();
void clen();
node* quit(node *p);
node* front(node* p);
int board(node *p);
node *writing(node *p);

void clen(){									//출력 2초후 지우는 함수 
	sleep(2);
	system("cls");
}
node *writing(node *p){	
	int i=0;							//글쓰는 함수      
	char ch;
	system("cls");  
	printf("한 계정당 3번만 쓸수 있습니다.\n"); 
	p->num+=1;
	if(p->num<3){
		if(p->code==1){
			printf("1.전체글 2.공지글\n");
			scanf("%d",&p->adwcode[p->num]);
		}
		if(p->code==2){
			printf("1.전체글 2.비밀글\n");
			scanf("%d",&p->wcode[p->num]);
		}
		printf("제목을 입력하세요\n");
		scanf("%s",p->title[p->num]);
		printf("글을 쓰시오.(엔터 후 컨트롤 z시 종료)\n");
		while(1){
			ch=getchar();
			if(ch==-1)
				break;
			p->write[p->num][i]=ch;
			i++;
		}
		p->write[p->num][i]='\0';
	}
	else
		printf("이미 3번 쓰셨습니다.");
	
}
node *findid(){  								//id찾는 함수 
	node *p;
	int i;
	char temail[50];
	printf("email를 입력하세요:");
	scanf("%s",temail);
	for(p=head;p!=NULL;p=p->link){
		if(strcmp(temail,p->email)==0){
			printf("그 email로 가입된 id는");
			for(i=0;i<strlen(p->id);i++){
				if(i<3){
					printf("%c",p->id[i]);
				}
				else
					printf("*");
			}
			break;
		}
		
	}
}
node *findpw(){												//pw찾는 함수 
	node *p;
	char tid[20];
	char temail[20];
	printf("id를 입력하세요");
	scanf("%s",tid);
	for(p=head;p!=NULL;p=p->link){
		if(strcmp(tid,p->id)==0){
			printf("email을 입력하세요:");
			scanf("%s",temail); 
			if(strcmp(temail,p->email)==0){
				printf("비밀번호는 %s",p->pw);
			}
		}
		break;
	} 
}
node *chpw(node *p){                                              //비번 바꾸는 함 수 
	char stpw[20];
	char cpw[20];
	printf("pw를 입력해주세요.");
	scanf("%s",stpw); 
	if(strcmp(p->pw,stpw)==0){
		printf("바꿀 비밀번호를 입력하세요:");
		scanf("%s",cpw);
		strcpy(p->pw,cpw);
		printf("pw를 바꿨습니다.");
	}
	else
		printf("비밀번호가 틀렸습니다.");
}
node *sigh(){														//회원가입 함수 좀
	node *p=(node*)malloc(sizeof(node));
	char adcode[20];
	char teid[20];
	char repw[20];
	int i;
	p->num=-1;
	printf("<회원가입>\n"); 
	while(1){
		printf("\nid를 입력하시오:");
		scanf("%s",p->id);
		if(overrap(p->id)==1)
		break;
	}
	printf("\npw를 입력하세요:");
	scanf("%s",p->pw); 
	while(1){
		printf("\n다시 비밀번호를 입력하세요:");
		scanf("%s",repw);
		if(strcmp(repw,p->pw)==0){
			printf("\n비밀번호가 확인 되었습니다.");
			break; 
		} 
		else
			printf("\n비밀번호가 다릅니다.");
	} 
	printf("\nemail를 입력해 주세요:");
	scanf("%s",p->email);
	printf("\n생일 8글자를 입력해주세요.");
	scanf("%d",&p->brith);
	printf("\n관리자 코드를 입력하세요.");
	scanf("%s",adcode);
	for(i=0;i<3;i++){
		p->title[i][0]='\0';
	
		p->write[i][0]='\0';
	}
	if(strcmp(adcode,ADcode)==0){
		p->code=1;
	}
	else
		p->code=2;
	
	if(p->code==1)
		printf("\n반갑습니다 관리자님.");
	else
		printf("\n반갑습니다");
	p->link=head;
	head=p;
	return head; 
}
int overrap(char *id){													
	node *p;
	for(p=head;p!=NULL;p=p->link){
		if(strcmp(id,p->id)==0){
			printf("이미 사용중인 id입니다.");
			return 0;
		}
	}
	return 1;
}
node* loginid(){												//로그인 함수  
	char logid[20];
	char logpw[20];
	node *p;
	printf("\nid를 입력해 주세요:\n");
	scanf("%s",logid); 
	for(p=head;p!=NULL;p=p->link){
		if(strcmp(logid,p->id)==0){
			for(;;){
				printf("\npw를 입력하시요:\n");
				scanf("%s",logpw);
					if(strcmp(logpw,p->pw)==0){
						printf("\n로그인 성공\n");
						return p;
						break;
					}
					else
						printf("\n로그인 실패\n");
			}
		} 
	}
	return NULL;
}

int menu(node *p){												//관리자와 일반 사용자들을 나누어 ㅁ나오는 메뉴 
	int n; 
	if(p->code==2){
		printf("<%s(일반 사용자)>\n1.pw바꾸기,2.게시판 보기,3.로그아웃,4.회원탈퇴\n",p->id);
		scanf("%d",&n);
		return n;
	}
	else if(p->code==1){
		printf("<%s(관리자)>\n1.pw바꾸기,2.게시판 보기,3.로그아웃,4.회원보기,5.회원 삭제,6.회원탈퇴\n",p->id);
		scanf("%d",&n);
		n+=4;
		return n;
	}
	
}
node *search(){                                                 //id찾기 
	char tempid[20];
	node *p;
	printf("id입력:");
	scanf("%s",tempid);
	for(p=head;p!=NULL;p=p->link){
		if(strcmp(tempid,p->id)==0)
			return p;
	}
	printf("\n입력하신 id는 없는 id입니다.");
	return NULL;
}
node* front(node* p) 											//행당 node의 앞 node 
{
	node* pre;
	for (pre = head; pre->link != p; pre = pre->link)
	{
	}
	return pre;
}
int board(node *pre){													//게시판 함 수 
	node *p;
	int m;
	int i=0;
	int j; 
	printf("<%s>님\n",pre->id);
	printf("=============게시판==============\n");
	printf("title				id\n");
	for(p=head;p!=NULL;p=p->link){
		for(j=0;j<3;j++){
			if(strcmp(p->title[j]," ")>0){
				if(p->adwcode[j]==2){
					printf("%s",p->title[j]);
					printf("%30s 공지글\n",p->id);
				}
			}
		}
	}	
	for(p=head;p!=NULL;p=p->link){
		for(j=0;j<3;j++){
			if(strcmp(p->title[j]," ")>0){
				if(p->adwcode[j]!=2){
					printf("%s",p->title[j]);
					printf("%30s",p->id);
					if(p->wcode[j]==2){
						printf("비밀글\n");
					}
					else
						printf("\n");
				}	
			}
		}
	}
	if(pre->code==1){
		printf("\n\n1.글쓰기,2.내 글보기,3.회원 글보기,4.돌아가기");
		scanf("%d",&m);
		return m;
	}
		
	else if(pre->code==2){
		printf("\n\n1.글쓰기,2.다른 사람 글보기,3.내 글보기,4.돌아가기"); 
		scanf("%d",&m);
		m+=4;
		return m;
	}	
}
void my(node *p){
	int i,j,n;
	while(1){
		printf("<%s>님의 글\n\n",p->id);
		for(i=0;i<3;i++){
		printf("%d번째 글       제목:%s\n",i+1,p->title[i]);
		}
		printf("1~3.글보기,4.돌아가기");
		scanf("%d",&n);
		if(n==1){
			system("cls");
			printf("1번째 글\n");
			puts(p->write[0]);
		} 
		if(n==2){
			system("cls");
			printf("1번째 글\n");
			puts(p->write[1]);
		}
		if(n==3){
			system("cls");
			printf("1번째 글\n");
			puts(p->write[2]);
		}
		if(n==4)
			break;
	}
}
void nam(node *p,node *pre){
	int i,j,n;
	while(1){
		printf("<%s>님의 글\n\n",p->id);
		for(i=0;i<3;i++){
		printf("%d번째 글       제목:%s\n",i+1,p->title[i]);
		}
		printf("1~3.글보기,4.돌아가기");
		scanf("%d",&n);
		if(n==1){
			if(p->wcode[0]==2){
				if(pre->code==1){
					system("cls");
					printf("1번째 글\n");
					puts(p->write[0]);
				}
				else{
					system("cls");
					printf("비밀글입니다.\n");
				}
			}
			else{
				system("cls");
				printf("1번째 글\n");
				puts(p->write[0]);
			}
		} 
		if(n==2){
			if(p->wcode[1]==2){
				if(pre->code==1){
					system("cls");
					printf("2번째 글\n");
					puts(p->write[1]);
				}
				else{
					system("cls");
					printf("비밀글입니다.");
				}
			}
			else{
				system("cls");
				printf("2번째 글\n");
				puts(p->write[1]);
			}
		}
		if(n==3){
			if(p->wcode[2]==2){
				if(pre->code==1){
					system("cls");
					printf("3번째 글\n");
					puts(p->write[2]);
				}
				else{
					system("cls");
					printf("비밀글입니다.");
				}
			}
			else{
				system("cls");
				printf("3번째 글\n");
				puts(p->write[2]);
			}
		}
		if(n==4)
			break;
	}
}
node* quit(node *p){										//탈퇴/제거 함수 
	int yn;
	char temppw[20];
	printf("탈퇴를 진행하시겠습니까?(1.예  2.아니요)");
	scanf("%d",&yn);
	if(yn==1){
		 printf("pw를 입력해 주세요");
		 scanf("%s",temppw);
		 if(strcmp(temppw,p->pw)==0){
		 	if(p==head){
		 		head=p->link;
				free(p);
			 }
			 else{
			 	 node *pre=front(p);
			 	 pre->link=p->link;
			 	 free(p);
			 }
			 printf("탈퇴되었습니다.");
			 return head;
		 }
		 else{
		 	printf("비밀번호가 틀렸습니다");	
			}
	} 
	else
		return head;		
}
node* adquit(node *p){										//탈퇴/제거 함수 
	int yn;
	char temppw[20];
	printf("회원삭제를 진행하시겠습니까?(1.예  2.아니요)");
	scanf("%d",&yn);
	if(yn==1){
		 printf("관리자 코드를 입력해 주세요");
		 scanf("%s",temppw);
		 if(strcmp(temppw,ADcode)==0){
		 	if(p==head){
		 		head=p->link;
				free(p);
			 }
			 else{
			 	 node *pre=front(p);
			 	 pre->link=p->link;
			 	 free(p);
			 }
			 printf("삭제되었습니다.");
			 return head;
		 }
		 else{
		 	printf("비밀번호가 틀렸습니다");	
			}
	} 
	else
		return head;		
}
void adprint(){													//관리자가 맴버 보기했을때 나오는 정보들 
	node *p;
	printf("<id>	<pw>	<birth>    <email>    0입력시 종료\n");
	for(p=head;p!=NULL;p=p->link){
		printf("%5s %5s %5d %5s",p->id,p->pw,p->brith,p->email);
		if(p->code==1)
			printf("	관리자\n");
		else
			printf("	일반 사용자\n"); 
	}
}
int main(int argc, char *argv[]) {
	int P,i,mecode,n,bcode;
	node *per;
	while(1){
		printf("\n1.회원가입 2.로그인 3.id/pw찾기 4.종료\n");
		scanf("%d",&P); 
		if(P==1){
			per=sigh();
			clen();
		}
		else if(P==2){
			per=loginid();
			if(per==NULL){
				printf("없는 회원입니다.");
				clen();
			}
			else{
				clen();
				while(1){
					mecode=menu(per);
					if(mecode==3||mecode==7){
						printf("로그아웃");
						clen();
						break;
					}
					if(mecode==8){
						adprint();
						scanf("%d",&n);
						if(n==0){
							printf("\n\n돌아 가는중..");
							clen();

						}
					} 
					if(mecode==1||mecode==5){
						chpw(per);
						clen();
					}
					if(mecode==4){
						quit(per);
						clen();
						break;
					}
					if(mecode==10){
						quit(per);
						clen();
						break;
					} 
					if(mecode==9){
						adquit(search());
						clen();
					}
					if(mecode==2||mecode==6){
						while(1){
							system("cls");
							bcode=board(per);
							if(bcode==1||bcode==5){
								 writing(per);
							}
							if(bcode==2||bcode==7){
								my(per);
							}
							if(bcode==3||bcode==6){
								nam(search(),per);
							}
							if(bcode==4||bcode==8){
								printf("나가는중..");
								clen();
								break;
							}
							}
						} 
					}
				}
		}
			else if(P==3){
				printf("1.id찾기,2.pw찾기");
				scanf("%d",&n);
				if(n==1){
					findid();
					clen(); 
				}
				else if(n==2){
					findpw();
					clen();
				}
				else{
					printf("오류");
					clen();
				}
			} 
			else if(P==4){
				break;
			}
			else{
				printf("오류입니다.");
			}
		}
		return 0;
	}
