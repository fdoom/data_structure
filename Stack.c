#include <stdio.h>
#define MAX 100		//스택 최대 크기

typedef int element;

//스택 구조
typedef struct Stack{
	element stack[MAX];
	int top;
}Stack;

//스택 초기화
void init(Stack * p) {
	p->top = 0;
}

//스택이 비었는지 확인
int empty(Stack * p) {
	if (p->top == 0) return 1;
	else return 0;
}

//스택이 가득차있는지 확인
int full(Stack* p) {
	if (p->top == MAX - 1) return 1;
	else return 0;
}

//스택에 데이터 추가
void push(Stack * p, element x) {
	if (full(p)) {
		printf("현재 스택 용량이 가득찼습니다.\n");
	}
	else {
		p->top += 1;
		p->stack[p->top] = x;
	}
}

//스택 제일 위에 있는 데이터 반환 후 제거
element pop(Stack * p) {
	element e;
	if (empty(p)) {
		printf("현재 스택이 비어있습니다.\n");
		exit(1);
	}
	else {
		e = p->stack[p->top];
		p->top -= 1;
		return e;
	}
}

//스택 제일 위의 데이터 반환
element peek(Stack * p)
{
	if (empty(p)) {
		printf("현재 스택이 비어있습니다.\n");
		exit(1);
	}
	else {
		return p->stack[p->top];
	}
}

//현재 스택 현황 출력
void print(Stack* p) {
	int i;
	printf("현재 스택 현황: ");
	for (i = 1; i <= p->top; i++)
		printf("%d ", p->stack[i]);
	printf("\n");
}

int main(void)
{
	Stack s;
	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	print(&s);

	printf("peek 결과: %d\n", peek(&s));
	printf("pop 결과: %d\n", pop(&s));
	printf("pop 결과: %d\n", pop(&s));

	print(&s);
	return 0;
}