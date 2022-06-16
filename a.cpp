#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, string> mp;
int completed=0, pending=0;

void addItem(int p, string text){ //This module helps the user to add his/ her activities along with priorities.
    mp[p]=text;
    cout<<"Added task: "<<text<<" with priority "<<p<<endl;
	pending++;
}

void showIncomplete() {
    //This module displays all the activities which are not completed.
	auto it = mp.begin();
	cout<<"No.\tTask\tPriority"<<endl;
	int i=1;
	while(it!=mp.end()){
        cout<<i<<": \t"<<it->second<<"\t"<<it->first<<endl;
        it++; i++;
	}
}

void deleteItem(int p) {
    /*This module works in the same way as markDone(). However, it is used to delete the activities which are not
      necessary and are to be deleted from the list.*/
	auto it = mp.begin();
	while(p!=1&&it!=mp.end()){
	    cout<<p<<endl;
	    p--;
	    it++;
	    if(it==mp.end()) --it;
	}
	if(p==1)
	{
	    cout<<"Deleted task #";
	    cout<<it->second<<endl;
	    mp.erase(it);
	    pending--;
	    completed++;
	}
}

void showUsage() { //This module guides the user on how to use the commands.
	cout<<"Usage :-"<<endl;
	cout<<"$ ./task add 2 hello world\t# Add a new item priority 2 and text \"hello world\" to the list"<<endl;
    cout<<"$ ./task ls\t# Show incomplete priority list items sorted by priority in ascending order"<<endl;
	cout<<"$ ./task del NUMBER\t# Delete the incomplete item with the given priority number"<<endl;
	cout<<"$ ./task done NUMBER\t# Mark the incomplete item with the given priority number as complete"<<endl;
	cout<<"$ ./task help\t\t# Show usage"<<endl;
	cout<<"$ ./task report\t\t# Statistics"<<endl;
	cout<<"$ ./task exit\t\t# Exit from the application"<<endl;
}

void statistics() {
    /*This module displays the statistics to the user about the count of activities which are completed and not completed.*/
	cout<<"Pending = "<<pending<<endl;
	cout<<"Completed = "<<completed<<endl;
}

void markDone(int p) {
    /*This module marks the specified activity as done and deletes it from the list of activities.*/
	deleteItem(p);
}


int main(){
    showUsage();
    cout<<endl;
    while(true) {
        string task, text, command;
        int priority;
        cout<<"$ ./task ";
        cin>>command;
        if(command=="add"){
            cin>>priority;
            getline(cin, text);
            addItem(priority, text);
        }
        else if(command=="ls"){
            showIncomplete();
        }
        else if(command=="del"){
            cin>>priority;
            deleteItem(priority);
        }
        else if(command=="done"){
            cin>>priority;
            markDone(priority);
        }
        else if(command=="help"){
            showUsage();
        }
        else if(command=="report"){
            statistics();
        }
        else if(command=="exit"){
            return 0;
        }
        else{
            cout<<"Error: Wrong syntax. Follow the instructions to continue: "<<endl;
            showUsage();
        }
    }
    return 0;
