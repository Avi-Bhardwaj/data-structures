# include <iostream>
# include <queue>
using namespace std;
struct node
{
	node* ne;
	node* se;
	node* sw;
	node* nw;
	int x;
	int y;
};
int position(node* root, int x, int y)
{
	int temp;
	if(x>=root->x && y>root->y)
		temp = 1;
	else if(x<root->x && y>=root->y)
		temp = 2;
	else if(x<=root->x && y<root->y)
		temp = 3;
	else if(x>root->x && y<=root->y)
		temp = 4;
	return temp;
}
node* newNode(int a, int b)
{
	node* added = new node();
	added->ne=NULL;
	added->nw=NULL;
	added->sw=NULL;
	added->se=NULL;
	added->x=a;
	added->y=b;
	return added;
}
node* insert(node* root, int data[])
{
	if(root==NULL)
	{
		return newNode(data[0],data[1]);
	}
	int pos = position(root,data[0],data[1]);
	if(pos==1)
	{
		root->ne = insert(root->ne,data);
	}
	else if(pos==2)
	{
		root->nw = insert(root->nw,data);
	}
	else if(pos==3)
	{
		root->sw = insert(root->sw,data);
	}
	else if(pos==4)
	{
		root->se = insert(root->se,data);
	}
	return root;
}
void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);
	node* temp;
	while(!q.empty())
	{
		temp = q.front();
		cout<<temp->x<<" "<<temp->y<<endl;
		if(temp->ne!=NULL)
			q.push(temp->ne);
		if(temp->nw!=NULL)
			q.push(temp->nw);
		if(temp->sw!=NULL)
			q.push(temp->sw);
		if(temp->se!=NULL)
			q.push(temp->se);
		q.pop();
	}
}
int main()
{
	int p[6][2] = {{3,7},{8,1},{6,6},{2,6},{1,7},{5,9}}; // data points
	node* root = NULL;
	for(int i=0;i<6;i++)
	{
		root = insert(root,p[i]);
	}
	levelorder(root);
	return 0;
}
