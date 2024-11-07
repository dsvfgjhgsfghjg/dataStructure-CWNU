#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char tel[12];
    char name[20];
    struct contact* next;
};

struct contact* contactAdd(struct contact** head);
void contactDel(struct contact** head, char* name);
void overWrite(struct contact* head, char* name);
void search(struct contact* head, char* name);
void printContacts(struct contact* head);
void freeContacts(struct contact* head);

int main() {
    struct contact* head = NULL;
    int choice;
    char name[20];

    while (1) {
        printf("\n��ϵ�˹���ϵͳ\n");
        printf("1. �����ϵ��\n");
        printf("2. ɾ����ϵ��\n");
        printf("3. �޸ĵ绰����\n");
        printf("4. ������ϵ��\n");
        printf("5. ��ӡ������ϵ��\n");
        printf("6. �˳�\n");
        printf("ѡ�����: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = contactAdd(&head);
                break;
            case 2:
                printf("����Ҫɾ������ϵ������: ");
                scanf_s("%s", name, (unsigned)_countof(name));
                contactDel(&head, name);
                break;
            case 3:
                printf("����Ҫ�޸ĵ绰�������ϵ������: ");
                scanf_s("%s", name, (unsigned)_countof(name));
                overWrite(head, name);
                break;
            case 4:
                printf("����Ҫ��������ϵ������: ");
                scanf_s("%s", name, (unsigned)_countof(name));
                search(head, name);
                break;
            case 5:
                printContacts(head);
                break;
            case 6:
                freeContacts(head);
                return 0;
            default:
                printf("��Ч��ѡ�������ԡ�\n");
        }
    }

    return 0;
}


struct contact* contactAdd(struct contact** head) {
    struct contact* newContact = (struct contact*)malloc(sizeof(struct contact));
    if (newContact == NULL) {
        exit(1);
    }
    newContact->next = *head;
    *head = newContact; // ������ϵ����ӵ�����ͷ��

    printf("������ϵ������: ");
    scanf_s("%s", newContact->name, (unsigned)_countof(newContact->name));
    printf("������ϵ�˵绰: ");
    scanf_s("%11s", newContact->tel, (unsigned)_countof(newContact->tel));

    return *head;
}

void contactDel(struct contact** head, char* name) {
    struct contact* temp, *pre = NULL;
    temp=*head;
    if (*head == NULL) {
        return;
    }
    while (temp!=NULL)
    {
        if (strcmp(temp->name,name)==0)
        {
            if (pre==NULL)
            {
                *head = temp->next;
            }else{
                pre->next = temp->next;
            }
            
            free(temp);
            return;
        }
        pre = temp;
        temp = temp->next;
        
    }
    
    }
    

void overWrite(struct contact* head, char* name) {
    struct contact* node = head;
    if (node == NULL) {
        printf("��ϵ���б�Ϊ��\n");
        return;
    }
    for (; node != NULL; node = node->next) {
        if (strcmp(node->name, name) == 0) {
            printf("�����µĵ绰���룺");
            scanf_s("%11s", node->tel, (unsigned)_countof(node->tel));
            return;
        }
    }
    printf("�Ҳ������ϵ���ϵ��\n");
}

void search(struct contact* head, char* name) {
    struct contact* node = head;
    if (node == NULL) {
        printf("��ϵ���б�Ϊ��\n");
        return;
    }
    for (; node != NULL; node = node->next) {
        if (strcmp(node->name, name) == 0) {
            printf("�ҵ���ϵ�ˣ��绰�����ǣ�%s\n", node->tel);
            return;
        }
    }
    printf("�Ҳ������ϵ���ϵ��\n");
}

void printContacts(struct contact* head) {
    struct contact* node = head;
    while (node != NULL) {
        printf("����: %s, �绰����: %s\n", node->name, node->tel);
        node = node->next;
    }
}

void freeContacts(struct contact* head) {
    struct contact* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}