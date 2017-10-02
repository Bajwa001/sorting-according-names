//
//  main.cpp
//  sorting according names
//
//  Created by Navroop Singh Bajwa on 25/09/17.
//  Copyright © 2017 Bajwa. All rights reserved.
//


#include "Header.h"

int main(int argc, const char * argv[]) {
    node *head=new node;
    head=NULL;
    char alpha[26]={0};
    node *pointers[26];
    for(int i=0;i<26;i++){
            pointers[i]=NULL;
    }
    cout<<"Enter no of words\n";
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        char t[50];
        cin.getline(t,50);
        cin.clear();
        alter(t);
        int indexinarray=getindex(t[0]);
        if(indexinarray!=-1){
            alpha[indexinarray]=t[0];
        }
        if(pointers[indexinarray]!=NULL) {
            insert(pointers[indexinarray],t,0);
        }
        else {pointers[indexinarray]=insert(head,t,1);
            if(head==NULL){
                head=pointers[indexinarray];
            }
        }
    }
    cout<<endl;
    display(head);
    cout<<endl;
    cout<<"\nClusters: \n";
    for(int i=0;i<26;i++)displaycluster(pointers[i]);
    cout<<"\nSorted Cluster :\n";
    for(int i=0;i<26;i++){
        sort(pointers[i],pointers[i]);
        displaycluster(pointers[i]);
    }
    cout<<"\nLinked list : \n";
    display(head);
    cout<<endl;
    char t[50];
    cin>>t;
    alter(t);
    searchforword(head,t);
    return 0;
}
