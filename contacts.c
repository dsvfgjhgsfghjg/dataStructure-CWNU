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
        printf("\n联系人管理系统\n");
        printf("1. 添加联系人\n");
        printf("2. 删除联系人\n");
        printf("3. 修改电话号码\n");
        printf("4. 搜索联系人\n");
        printf("5. 打印所有联系人\n");
        printf("6. 退出\n");
        printf("选择操作: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = contactAdd(&head);
                break;
            case 2:
                printf("输入要删除的联系人姓名: ");
                scanf_s("%s", name, (unsigned)_countof(name));
                contactDel(&head, name);
                break;
            case 3:
                printf("输入要修改电话号码的联系人姓名: ");
                scanf_s("%s", name, (unsigned)_countof(name));
                overWrite(head, name);
                break;
            case 4:
                printf("输入要搜索的联系人姓名: ");
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
                printf("无效的选择，请重试。\n");
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
    *head = newContact; // 将新联系人添加到链表头部

    printf("输入联系人姓名: ");
    scanf_s("%s", newContact->name, (unsigned)_countof(newContact->name));
    printf("输入联系人电话: ");
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
        printf("联系人列表为空\n");
        return;
    }
    for (; node != NULL; node = node->next) {
        if (strcmp(node->name, name) == 0) {
            printf("输入新的电话号码：");
            scanf_s("%11s", node->tel, (unsigned)_countof(node->tel));
            return;
        }
    }
    printf("找不到符合的联系人\n");
}

void search(struct contact* head, char* name) {
    struct contact* node = head;
    if (node == NULL) {
        printf("联系人列表为空\n");
        return;
    }
    for (; node != NULL; node = node->next) {
        if (strcmp(node->name, name) == 0) {
            printf("找到联系人，电话号码是：%s\n", node->tel);
            return;
        }
    }
    printf("找不到符合的联系人\n");
}

void printContacts(struct contact* head) {
    struct contact* node = head;
    while (node != NULL) {
        printf("姓名: %s, 电话号码: %s\n", node->name, node->tel);
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