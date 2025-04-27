#include <iostream>
 using namespace std;
 
 class student {
 public:
     int rollno;
     string name, add;
     student *lc, *rc;
 
     void create();
     void insert(student *root, student *next);
     void display(student *root);
     int height(student *root);
 } *root, *st[100];
 
 
 void student::create() {
     int ch;
     student *next;
     root = new student;
     cout << "Enter the student information (Rollno, Name, Address): ";
     cin >> root->rollno >> root->name >> root->add;
     root->lc = root->rc = NULL;
 
     do {
         cout << "Do you want to enter more students? (0/1): ";
         cin >> ch;
         if (ch == 1) {
             next = new student;
             cout << "Enter the student details (Rollno, Name, Address): ";
             cin >> next->rollno >> next->name >> next->add;
             next->lc = next->rc = NULL;
             insert(root, next);
         }
     } while (ch == 1);
 }
 
 void student::insert(student *root, student *next) {
     char chr;
     cout << "Where do you want to add the student? (L/R): ";
     cin >> chr;
 
     if (chr == 'L' || chr == 'l') {
         if (root->lc == NULL) {
             root->lc = next;
         } else {
             insert(root->lc, next);
         }
     } else if (chr == 'R' || chr == 'r') {
         if (root->rc == NULL) {
             root->rc = next;
         } else {
             insert(root->rc, next);
         }
     } else {
         cout << "Invalid choice. Please enter L or R.\n";
     }
 }
 
 void student::display(student *root) {
     if (root == NULL) {
         return;
     }
     display(root->lc);
     cout << "Rollno: " << root->rollno << ", Name: " << root->name << ", Address: " << root->add << endl;
     display(root->rc);
 }
 
 int student::height(student *root) {
     if (root == NULL) {
         return 0;
     }
 
     int lht = height(root->lc);
     int rht = height(root->rc);
 
     return (lht, rht) + 1;
 }
 
 int main() {
     student obj;
     obj.create();
     cout << "Displaying student details in Inorder Traversal:";
     obj.display(root);
     cout << "Height of the tree: " << obj.height(root) << endl;
     return 0;
 }
