#include"������.h"
RNode* Copy(RNode* head) {
	//1��ֻ���ƽڵ���val��next�����½ڵ�����Ͻڵ����
	//2������random�ĸ���
	//3��������
	if (head == NULL)
		return NULL;

	RNode* oldNode = head;
	while (oldNode) {
		RNode* newNode = (RNode*)malloc(sizeof(RNode));
		newNode->val = oldNode->val;
		newNode->next = oldNode->next;
		oldNode->next = newNode;
		oldNode = oldNode->next->next;
	}

	oldNode = head;
	while (oldNode) {
		RNode* newNode = oldNode->next;

		if (oldNode->random == NULL)
			newNode->random = NULL;
		else {
			newNode->random = oldNode->random->next;
		}
		oldNode = newNode->next;
	}

	oldNode = head;
	RNode* newHead = head->next;
	while (oldNode) {
		RNode* newNode = oldNode->next;

		oldNode->next = newNode->next;
		if (newNode->next != NULL)
			newNode->next = newNode->next->next;
		oldNode = oldNode->next;
	}
	return newHead;
}