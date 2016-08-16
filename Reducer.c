#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ListNode
{
	char *word;
	int count;
	struct ListNode* next;
};


struct ListNode* insert_list(struct ListNode* head,char *value){
 	struct ListNode* head_node;
 	char *new_val;
 	new_val=(char *)malloc(sizeof(char)*strlen(value));
 	strcpy(new_val,value);
 	head_node=head;
 	if(head==NULL)
 	{
 	struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
 	new_node->word=(char *)malloc(sizeof(char)*strlen(value));
 	strcpy(new_node->word,value);
 	new_node->count=1;
 	new_node->next=NULL;
 	head=new_node;
 	return head;
    }
 	else
 	{
 		   
 			while(head_node->word[0]!=new_val[0])
 			 {
 			 	
				printf("(%s,%d) \n",head_node->word,head_node->count);
			    head_node=head_node->next;	
				if(head_node==NULL)
				{
					struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
                	new_node->word=(char *)malloc(sizeof(char)*strlen(value));
 	               strcpy(new_node->word,value);
                	new_node->count=1;
 	               new_node->next=NULL;
 	               return new_node;
				}			 
				}
 			 head=head_node;
 			 while(strcmp(head_node->word,new_val)!=0&& head_node->next!=NULL)
 			 {
 			 head_node=head_node->next;
			 }
 			 if(head_node->next==NULL)
 			 {
 			 	if(strcmp(head_node->word,new_val)==0)
 			 	{
 			 	head_node->count=head_node->count+1;	
				}
 			 	else{
				  
 			 		struct ListNode* new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
                	new_node->word=(char *)malloc(sizeof(char)*strlen(value));
 	               strcpy(new_node->word,value);
                	new_node->count=1;
 	               new_node->next=NULL;
                    head_node->next=new_node;
              }
			 }
 			 else
 			 {
 			 	head_node->count=head_node->count+1;
			 }
	   }
		return head;
	}
	
 

int main()
{   char str[900],c,dest[900];
	struct ListNode* s1=NULL;
	memset(&dest[0], 0, sizeof(dest));
    while(scanf("%s", str) != EOF)
    {
    	
		int i=1,j=-1;
		while(str[i]!=',')
        {   j++;
        	dest[j]=str[i];
        	i++;
		}
        s1=insert_list(s1,dest);
        memset(&dest[0], 0, sizeof(dest));
    }
    while(s1!=NULL)
    {
    	printf("(%s,%d) \n",s1->word,s1->count);
    	s1=s1->next;
	}

}
