#include<bits/stdc++.h>
 
using namespace std ;
class Node {
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* vecToLL(vector<int>&arr){
    Node* head  = new Node(arr[0]);
    Node* mover = head ;
    for(int i=1 ; i< arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp ;
    }
    return head ;
}

vector<vector<int>> spiralMatrix(int m, int n, Node* head) {
    vector<vector<int>>matrix(m,vector<int>(n,-1));

    int id = 0 ; // 0 ,1, 2, 3 
    int top = 0 ,down = m-1 , left = 0 ,right = n-1;

            while(top <= down && left <= right) {
            if(id == 0) { //left to right
                for(int i = left; head != NULL && i <= right; i++) {
                    matrix[top][i] = head->data;
                    head = head->next;
                }
                top++;
            }

            if(id == 1) { //top to down
                for(int i = top; head != NULL && i <= down; i++) {
                    matrix[i][right] = head->data;
                    head = head->next;
                }
                right--;
            }

            if(id == 2) { //right to left
                for(int i = right; head != NULL && i >= left; i--) {
                    matrix[down][i] = head->data;
                    head = head->next;
                }
                down--;
            }

            if(id == 3) { //down to top
                for(int i = down; head != NULL && i >= top; i--) {
                    matrix[i][left] = head->data;
                    head = head->next;
                }
                left++;
            }

            id = (id+1)%4; //0, 1, 2, 3
        }
    return matrix ; 
}
 
int main(){
 
    int m = 3, n = 5;
    vector<int> arr = {3,0,2,6,8,1,7,9,4,2,5,5,0} ;
    Node* head = vecToLL(arr);
    vector<vector<int>>ans = spiralMatrix(m,n,head);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();i++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}