//
//  Header.h
//  sorting according names
//
//  Created by Navroop Singh Bajwa on 25/09/17.
//  Copyright © 2017 Bajwa. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string.h>
#include <iostream>
#include <fstream>
#include <locale>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct node {
    char *word;
    struct node *next;
};

node *insert(node *head,char wor[],int i){
    node *t=new node;
    t->word=new char[50];
    strcpy(t->word, wor);
    if(i==0){
        node *pre=head;
        char start=head->word[0];
        while(head!=NULL&&head->word[0]==start){
            pre=head;
            head=head->next;
        }
        t->next=head;
        pre->next=t;
        return NULL;
    }else{
        
        if(head==NULL){
            t->next=NULL;
            return t;
        }else{
            while(head->next!=NULL){
                head=head->next;
            }
            head->next=t;
            t->next=NULL;
            return t;
        }
    }
    
}

void displaycluster(node *head){
    if(head!=NULL){char start=head->word[0];
    while(head!=NULL&&head->word[0]==start){
        cout<<"\""<<head->word<<"\""<<"  ";
        head=head->next;
    }
        cout<<endl;}
}

void display(node *head){
    while(head!=NULL){
        cout<<head->word<<" ";
        head=head->next;
    }
    cout<<endl;
}

int getindex(char t){
    int pos;
    pos=t-'a'; //@gupta
    if(pos>=0&&pos<26)return pos;
    else return -1;
}

void alter(char  t[]){
    locale loc;
    int l=(int)strlen(t);
    //cout<<l<<endl;
    for(int i=0;i<l;i++){
        if(t[i]!=' ')t[i]=tolower(t[i],loc);
    }
    int co=0;
    for(int i=0;i<l;i++){
        if(t[i]==' '){
            co++;
        }else break;
    }
    for(int j=0;j<l;j++){
        t[j]=t[j+co];
    }
    //cout<<t<<endl;
    t[l-co]='\0';
    l-=co;
    for(int i=l-1;i>=0;i--){
        if(t[i]==' '){
            t[i]='\0';
        }else break;
    }
    cout<<"\""<<t<<"\""<<endl;
}
bool compare(char a[],char b[]){
    int l1=(int)strlen(a),l2=(int)strlen(b);
    int i=0;
    while(i<l1&&i<l2){
        if(a[i]==b[i])i++;
        else{
            if(a[i]>b[i]) return true;
            else return false;
        }
    }
    if(l1>l2)return true;
    return false;
}

void sort(node *head,node *start){
    if(head!=NULL&&head->next!=NULL&&head->word[0]==head->next->word[0]){
            if(compare(head->word,head->next->word)){
                char temp[50];
                strcpy(temp, head->word);
                strcpy(head->word, head->next->word);
                strcpy(head->next->word, temp);
                sort(start,start);
            }
        sort(head->next,start);
        }
}



#endif /* Header_h */
