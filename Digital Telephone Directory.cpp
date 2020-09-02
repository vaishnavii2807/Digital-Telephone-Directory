#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include <chrono> 
#include <ctime> 
#include<windows.h>
#include<conio.h>
using namespace std;

class node{
public:
string category;
string name;
long long int mob;
node *right;
node *left;
};

class Contacts{
public:
node *root;
void create_node();
void insert_node(node*, node*,string);
void display(node *);
node * search(string);
node * del(node * root, string key);
node * min(node *);
Contacts(){
root = NULL;
}
}c;

void Contacts::create_node(){
string s;
node *check;
node *temp = new node;
cout << "Enter Work/Home:" << endl;
cin >> temp->category;
cout << "Enter Name:" << endl;
cin >> temp->name;
cout << "Enter Mobile Number: " << endl;
cin >> temp->mob;
temp->left = NULL;
temp->right = NULL;
if(root == NULL){
root = temp;
}
else{
check = search(temp->name);
if(check != NULL){
cout << "Contact with the Same Name Exists!" << endl;
cout << "Contact couldn't be inserted!" << endl;
return;
}
s = temp->name;
transform(s.begin(),s.end(),s.begin(),::tolower);
insert_node(root, temp, s);
}
cout << "Record Inserted Successfully" << endl;
}

void Contacts::insert_node(node *root, node *temp,string name)
{
string t= root->name;
transform(t.begin(),t.end(),t.begin(),::tolower);
if(name.compare(t) < 0){
if(root->left == NULL)
root->left = temp;
else
insert_node(root->left,temp,name);
}
else{
if(root->right == NULL)
root->right = temp;
else
insert_node(root->right,temp,name);
}
}

void Contacts::display(node *temp)
{
if(temp==NULL)
cout<<"Directory is Empty."<<endl;
else
{
if(temp->left!=NULL)
display(temp->left);
cout << temp->category << endl;
cout << "Name: " << temp->name << endl;
cout << "Mobile No.: " << temp->mob << endl;
cout << setfill('-') << setw(50) << "-" << endl;
if(temp->right!=NULL)
display(temp->right);
}
}

node * Contacts::del(node * root, string key){
node * temp;
if(root == NULL){
cout << "Contact " << key << " Does not exist" << endl;
return root;
}
if(key.compare(root->name) < 0){
root->left = del(root->left,key);
return root;
}
if(key.compare(root->name) > 0){
root->right = del(root->right,key);
return root;
}

if(root->right == NULL && root->left == NULL){
temp = root;
delete temp;
return root;
}

if(root->right == NULL){
temp = root;
root = root->left;
delete temp;
return root;
}

else if(root->left == NULL){
temp = root;
root = root->right;
return root;
}

temp = min(root->right);
temp->name = root->name;
root->right = del(root->right, temp->name);
return root;
}

node * Contacts::min(node * root){
while(root->left!=NULL){
root = root->left;
}
return root;
}

node * Contacts::search(string key){
node *temp = root;
int c;
while(temp!=NULL){
c = key.compare(temp->name);
if(c == 0){
return temp;
}
else if(c < 0){
temp = temp->left;
}
else{
temp = temp->right;
}
}
return NULL;
}

int startscreen(){
int choice;
cout << endl << setfill('<') << setw(20) << "Contacts" << setfill('>') << setw(20) << ">"<< endl;
cout << "Enter Appropriate Option:" << endl;
cout << "1.Add a Contact" << endl;
cout << "2.Search" << endl;
cout << "3.Display All" << endl;
cout << "4.Delete" << endl;
cout << "5.Update" << endl;
cout << "6.Exit" << endl;
cin >> choice;
return choice;
}

void operation(){
string key;
node * temp;
while(1){
switch(startscreen()){
case 1:
c.create_node();
break;
case 2:
cout << "Enter Search Key: " << endl;
cin >> key;
temp = c.search(key);
if(temp == NULL)
cout << "Not Found!" << endl;
else{
cout << setfill(' ') <<setw(11) << left << "Name: " << temp->name << endl;;
cout << "Mobile No.: " << temp->mob << endl;
}
break;
case 3:
cout << "All Contacts:" << endl;
c.display(c.root);
break;
case 4:
cout << "Enter the name of contact to be deleted: " << endl;
cin >> key;
c.root = c.del(c.root, key);
cout << "Deleted Successfully" << endl;
break;
case 5:
cout << "Enter the name of the contact you want to update: " << endl;
cin >> key;
temp = c.search(key);
if(temp !=NULL){
cout << setfill(' ') << setw(22) << left << "Current category: " << temp->category << endl;
cout << setw(22) << left << "Current Name: " << temp->name << endl;
cout << setw(22) << left << "Current Mobile No.: " << temp->mob << endl;
cout << setw(22) << left << "Home/work: ";
cin>> temp->category;
cout << setw(22) << left << "Enter New Name: ";
cin >> temp->name;
cout << "Enter New Mobile No. :";
cin >> temp->mob;
cout << "Updated Successfully" << endl;
}
else{
cout << "Contact " << key << " does not exist!" << endl;
}
break;
case 6:
return;
default:
cout << "Enter Appropriate Choice!" << endl;
}
}
}

int login()
{
	int pwd,count=2;
	int j=3;
	system("color 01");
	while(j>0)
	{ 
	 system("cls");
	 cout<<"\n\n\n\n\n\n";
	cout<<setw(83)<<"Enter Password"<<endl;
	if(j==3)
	cout<<setw(71)<<"Only "<<j<<" attempt allowed"<<endl;
	cout<<setw(78)<<"Password: ";
	cin >> pwd;
	if(pwd!=1234)
{   cout<<endl;
	cout <<setw(84)<<"Incorrect password"<<endl;
	--j;
	if(j>0)
	cout <<setw(81)<<"Try again\n"<<setw(70)<<"Only "<<j<<" attempt left"<<endl;
	cout<<"\n\n";
	if(j==0)
	{ Sleep(1000);
	 system("cls");
	 system("color 04");
	 cout<<"\n\n\n\n";
	 cout<<setw(80)<<"Failed to login";
	exit(0);
}  Sleep(1000);
}
	else
	{
	     count++;
	     cout<<count;
	     return count;
         break;
	     
	}	
}
}
//-------------------------------------------------------------------------------------------
int main(){
int count=login();
 
if(count>0)
{ system("cls");
cout<<"\n\n\n\n\n\n\n";
system("color 4F");
 auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
 cout<<setw(79)<<"WELCOME"<<endl;
 cout<<setw(90)<<ctime(&timenow)<<endl;

cout<<setw(79)<<"Loading";
for(int i=0; i<5; i++)
{
Sleep(1000);
cout<<".";
		}
	 }
system("cls");
operation();
return 0;
}

