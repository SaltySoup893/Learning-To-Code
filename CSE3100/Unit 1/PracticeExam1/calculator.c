#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"

node* addition(node* num1, node* num2) {
	node* result = NULL;
	int carry = 0;
	while(num1 != NULL && num2 != NULL) {
		int sum = num1->v + num2->v + carry;
		int node_sum = sum % 10;
		result = prepend(result, new_node(node_sum));
		carry = (node_sum==sum) ? 0 : 1;
		num1 = num1->next;
		num2 = num2->next;
	}

	if(num1 == NULL && num2 != NULL) {
		while(num2 != NULL) {
			int sum = carry + num2->v;
			int node_sum = sum % 10;
			result = prepend(result, new_node(node_sum));
			carry = (node_sum==sum) ? 0 : 1;
			num2 = num2->next;
		}
		if(carry) result = prepend(result, new_node(carry));
	}
	else if(num2 == NULL && num1 != NULL) {
		while(num1 != NULL) {
			int sum = carry + num1->v;
			int node_sum = sum % 10;
			result = prepend(result, new_node(node_sum));
			carry = (node_sum==sum) ? 0 : 1;
			num1 = num1->next;
		}
		if(carry) result = prepend(result, new_node(carry));
	}
	else {
		if(carry) result = prepend(result, new_node(carry));
	}
	return result;
}

node* subtraction(node *num1,node *num2){
	node *result = NULL;
	int borrow = 0;
	
	while(num1 != NULL && num2 != NULL) {
		int diff = 0;
		if ((num2->v + borrow) > num1->v){
			diff = (num1->v + 10) - (num2->v + borrow);
			borrow = 1;
		} else {
			diff = num1->v - (num2->v + borrow);
			borrow = 0;
		}
		result = prepend(result, new_node(diff));
		num1 = num1->next;
		num2 = num2->next;
	}


	while(num1 != NULL) {
		int diff = 0;
		if (num1->v < borrow) {
			result = prepend(result, new_node(num1->v + 9));
			borrow = 1;
		} else {
			diff = num1->v;
			result = prepend(result, new_node(diff - borrow));
			borrow = 0;
		}
		num1 = num1->next;
	}
	return result;
}


node *remove_leading_zeros(node *num){
	node *temp = num;
	while(temp!=NULL && temp->v == 0){
	    node *temp2 = temp;
	    temp = temp->next;
	    free(temp2);
	}
	return temp;
}

int main(int argc,char *argv[]){
	if(argc < 3){
		printf("Usage: ./calculator number1 number2\n");
		exit(0);
	}
	node *num1=NULL,*num2 = NULL;
	node *sum = NULL;
	node *difference = NULL;

	for(int i=0;i<strlen(argv[1]);i++){
		if(!isdigit(argv[1][i])){
			printf("Invalid inputin number1\n");
			exit(0);
		}
		num1 = prepend(num1,new_node(argv[1][i]-'0'));
	}
	for(int i=0;i<strlen(argv[2]);i++){
		if(!isdigit(argv[2][i])){
			printf("Invalid input in number2\n");
			exit(0);
		}
		num2 = prepend(num2,new_node(argv[2][i]-'0'));
	}
	sum = addition(num1,num2);
	difference = subtraction(num1,num2);

    	sum = remove_leading_zeros(sum);
    	difference = remove_leading_zeros(difference);
    
    	print_list(sum);
    	print_list(difference);

    	delete_list(num1);
    	delete_list(num2);
    	delete_list(sum);
    	delete_list(difference);
    	return 0;
}
