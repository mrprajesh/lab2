#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#define DEBUG 0
#define print std::cout<<
#define dout if(DEBUG) std::cout<<
 
class BiNode{
	public:
		BiNode(BiNode *node, int JID, int pr, int dur){
				this->priority=pr;
				this->JID=JID;
				this->duration=dur;
				this->left = NULL;
				this->right = NULL;
				this->parent = node;
		}

		
		int getJID(){
				return JID;
		}
		int getP(){
				return priority;
		}
		int getD(){
				return duration;
		}
		
		BiNode* getLeft(){
				return left;
		}
		BiNode* getRight(){
				return right;
		}
		BiNode * setChild(BiNode *node){
			if(this->getLeft()==NULL){
				left=node;
			}else{
				right=node;			
			}
		}
	   

	private:
		int JID;       
		int priority;
		int duration;
		BiNode * left;
		BiNode * right;
		BiNode * parent;
};
 
 
class BiHeap{
	public:
		int flag;
		BiHeap(){
				root=NULL;
				flag=0;
		}
		~BiHeap(){
				root=NULL;
		}
		void error(std::string msg,int);
		unsigned readInput(std::string file);
		void buildHeap(int a[], int b[],int v[]);
		void listAll();
		void treePrint(BiNode *node);
		void outputData(std::string file) ;
		void heapSort();
	private:
		BiNode *root;
		BiNode *endNode;
		int size;
		   
};

void BiHeap::error(std::string msg,int errorNum=101) {
		std::cout << "ERROR: " << errorNum<< " "<< msg << std::endl;
}

void BiHeap::buildHeap(int J[], int P[],int D[]){
	int i=1;
	std::queue <BiNode*> q;	
	if (root==NULL){
		BiNode * node = new BiNode(NULL,J[0],P[0],D[0]);
		root= node;
		q.push(root);
		
		while(i<size && !q.empty() ){
			node=q.front();
			q.pop();

			BiNode * child = new BiNode(node,J[i],P[i],D[i]);
			node->setChild(child);
			i++;
			endNode=child;
			q.push(child);
			if(i<size){
				BiNode * child = new BiNode(node,J[i],P[i],D[i]);
				node->setChild(child);
				i++;
				endNode=child;
				q.push(child);
			}
		
			
		}
	}else{
		error("HEAP already exists")	;
	}
	//heapfy
	
}
unsigned BiHeap::readInput(std::string file) {
	std::ifstream in;
	std::string line;

	int pr[10], JID[10], dur[10] ;
	int j,p,d;
	int count,i=0;
	in.open(file.c_str()); 
	if(in.fail())
		error ("input File NOT found" );

	in >>  count;
	this->size=count; 
	print count << std::endl;	
	in >>  j >> p >> d ;
	JID[i]=j ; pr[i]=p ;dur[i]=d;		
	i++;
	while (i<count) {
		print j << "=" << p << "=" << d << std::endl;
		in >> j >> p >> d;
		JID[i]=j ; pr[i]=p ;dur[i]=d;		
		i++;
	}
	in.close();
	buildHeap(JID,pr,dur);
	return 0;
	
}
void BiHeap::heapSort(){

}
void BiHeap::outputData(std::string file) {
	  std::ofstream outfile;
	  outfile.open (file.c_str());
	  outfile << "Test"<<std::endl;  
	  int i=0; 
	  outfile << i <<std::endl;
	  outfile.close();
}

void BiHeap::listAll(){
	treePrint(root);
	//print "---------------" << std::endl;
}
void BiHeap::treePrint(BiNode *node){
	if(node!=NULL){
		std::cout << node->getJID() <<" "<< node->getP() <<" "<< node->getD()<< std::endl;
		treePrint(node->getLeft());
		treePrint(node->getRight());
	}      
}

int main(int argc, char * args[]){
	   
	if (argc != 3) {
		std::cout << "Invalid number of arguments.\nUsage: " << args[0] << " <INPUT FILE> <OUTPUT FILE>\n";
		return 1;
	}
	BiHeap b;
	b.readInput(args[1]);
	b.listAll();	
//	b.heapSort();
//	b.outputData(args[2]);
	return 0;
}

