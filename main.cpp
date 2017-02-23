#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include <iterator>
using namespace std;

class Automata
{
    map<pair<int,char>,int> transition;
    vector<int> final_state;
    int q;
    public:
    Automata(int start)
    {
        q=start;
    }
    void add_transition(int i,int j,char c);	//Method to add transitions
    void add_finalstate(int  n);		//Method to add final states of DFA into the vector
    void validate_string(const char s[]);	//Method to validate the input string according to the given states and transitions
};
void Automata:: add_transition(int i,int j,char c)
{
    pair<int,char> t(i,c);	//Creating a pair for current state and the input character
 // cout<<"\nPair 1st, Pair 2nd: "<<t.first<<" "<<t.second<<" final: "<<j;
    transition.insert(pair<pair<int,char>,int> (t,j));	//Inserting the pair into map with key as the next state
}
void Automata:: add_finalstate(int n)
{
    int i,state;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter Final State "<<i+1<<": ";
        cin>>state;
        final_state.push_back(state);
    }
 // vector<int>:: iterator iter=final_state.begin();
 // for(;iter!=final_state.end();iter++)
 // cout<<*iter<<" ";

}
void Automata:: validate_string( const char s[])
{
    int i,len,cur_state=q,flag=0;
    len=strlen(s);
    map<pair<int,char>,int> :: iterator iter;
    for(i=0;s[i]!='\0';i++)
    {
        pair<int,char> t(cur_state,s[i]);		// create pair with current state and current input symbol
     // cout<<"\npair first: "<<t.first;
     // cout<<"\npair second: "<<t.second;
        iter=transition.find(t);			//Check if pair exists in the map containing all transition rules
     // cout<<"\nSecond val: "<<iter->second;
        if(iter!=transition.end())
        {
     //      cout<<iter->second;
     //      cout<<"\nInside if... map second val: "<<iter->second<<endl;
             cur_state= iter->second;			//If transition found, then set the new current state(key of the map)
     //      cout<<cur_state;
        }
        else{
            flag=1;	//if transition not found then set flag 
            break;
        }
    }
    vector<int> :: iterator iter1;
    iter1=find(final_state.begin(),final_state.end(),cur_state);	//Check if the current state is the final state of the DFA
    if(iter1!=final_state.end() && flag!=1 )
        cout<<"\nValid String";					//If current state is final state and flag not zero then it is a valid string
    else
        cout<<"\nInvalid String";
}
int main()
{
    Automata A(0);
    int states,final,i,j,initial,next;
    char s[20],symbol,ch;
    cout<<"\nEnter the number of states: ";
    cin>>states;
    cout<<"\nEnter the number of final states: ";
    cin>>final;
    A.add_finalstate(final);
    while(1)
    {
        cout<<"\nEnter transition (initial state ,symbol ,next state) : ";
        cin>>initial>>symbol>>next;
        A.add_transition(initial,next,symbol);		//Enter transition into map
        cout<<"\nMore transition? (y/n): ";
        cin>>ch;
        if(ch=='n' || ch=='N')
            break;
    }
    while(1){
    cout<<"\nEnter the string to validate: ";
    cin>>s;
    A.validate_string(s);
    cout<<"\nEnter another string?(y/n): ";
    cin>>ch;
    if(ch=='n' || ch=='N')
            break;

	}

}
