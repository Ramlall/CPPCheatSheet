
# Introduction - this cheat sheet is to remember C++ language features quickly for algorithm contests

//To-do:
//Enhance Stack, queue, vector for nodes instead of primitive data types.

# Data structures

array
vector
queue
stack
priority queue
set
unordered map


# Algorithms

bfs
dfs

All includes



///////////////////////////////////////////////////////
////////// VECTOR ////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Pass by reference
void Print(vector< vector<int> > &inceptionvec)
    {
    cout << "Vector of vectors: " << endl;
    // Go through each row
    for(int i = 0; i < inceptionvec.size(); i++)
        {
        // Go through each column
        for(int j = 0; j < inceptionvec[i].size(); j++)
            {
            cout << inceptionvec[i][j] << " ";
            }
        cout << endl;
        }
    }

int main() 
    {
    cout << "C++ Vector Code" << endl;
    
    // Create a vector
    vector<int> myvec;
    
    // Add some numbers to the vector
    myvec.push_back(4);
    myvec.push_back(3);
    myvec.push_back(2);
    myvec.push_back(1);
    
    // Sort the vector.
    std::sort(myvec.begin(), myvec.begin()+myvec.size());
    
    // Print the sorted vector.
    cout << "Sorted vector: " << endl;
    for(int i = 0; i < myvec.size(); i++)
        {
        cout << myvec[i] << " ";
        }
    cout << endl << endl;
    
    // Create a vector of vectors
    vector< vector<int> > inceptionvec;
    // Fill the vectors.
    int counter = 0;
    for(int i = 0; i < 3; i++)
        {
        // Create a row and add it to the vector.
        vector<int> row;
        inceptionvec.push_back(row);
        for(int j = 0; j < 3; j++)
            {
            counter += 1;
            
            // Add this counter to the row
            inceptionvec[i].push_back(counter);
            }
        }
    
    // Print our vector of vectors.
    Print(inceptionvec);
	
	return 0;
    }
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
////////// Queue ////////////////////////////////////
#include <iostream>
#include <queue>

using namespace std;

int main() 
    {
    cout << "C++ Queue Code" << endl;
    
    // Create a queue
    queue<int> myqueue;
    
    // Add some numbers to the queue
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);
    myqueue.push(4);
    
    // Print each number and remove it from the queue
    cout << "Printed queue: " << endl;
    while(myqueue.empty() == false)
        {
        int mynum = myqueue.front();
        cout << mynum << " ";
        myqueue.pop();
        }
    cout << endl;
    
	return 0;
    }
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
////////// Stack ////////////////////////////////////
#include <iostream>
#include <stack>

using namespace std;

int main() 
    {
    cout << "C++ Stack Code" << endl;
    
    // Create a stack
    stack<int> mystack;
    
    // Add some numbers to the queue
    mystack.push(4);
    mystack.push(3);
    mystack.push(2);
    mystack.push(1);
    
    // Print each number and remove it from the stack
    cout << "Printed stack: " << endl;
    while(mystack.empty() == false)
        {
        int mynum = mystack.top();
        cout << mynum << " ";
        mystack.pop();
        }
    cout << endl;
    
	return 0;
    }
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
////////// Priority Queue ////////////////////////////////////
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() 
    {
    cout << "C++ Priority Queue Code" << endl;
    
    // Create a priorityqueue
    priority_queue<int> mypq;
    // If we wanted the queue to have smaller numbers be prioritized first
    //priority_queue <int, vector<int>, greater<int> > mypq;
    
    // Add some numbers to the priorityqueue
    mypq.push(4);
    mypq.push(2);
    mypq.push(2);
    mypq.push(6);
    mypq.push(5);
    mypq.push(3);
    mypq.push(1);
    
    // Print each number and remove it from the priorityqueue
    cout << "Printed priority queue: " << endl;
    while(mypq.empty() == false)
        {
        int mynum = mypq.top();
        cout << mynum << " ";
        mypq.pop();
        }
    cout << endl;
    
    
    // Create a priority queue of a node.
    // The node we care about
    struct Node
        {
        bool isFood;
        int quant;
        string name;
        
        // Constructor for this Node
        Node(bool food, int q, string n)
            {
            isFood = food;
            quant = q;
            name = n;
            }
        
        Node(): isFood(false), quant(0), name("food") {}
        };
    
    /* Node initialization
    Node* myNode = new Node(true, 10, "bread");
    cout << myNode->name << endl;
    */
    
    // Create a comparison tool for the priority queue to know what's best
    struct SmallerQuant
        {
        bool operator()( const Node* a, const Node* b ) const 
           {
           // Returns true if a is bigger than b, meaning smaller numbers are prioritized.
           return a->quant > b->quant;
           }
        };
    
    // The priority queue
    priority_queue<Node*, vector<Node*>, SmallerQuant> pq;
    
    // Add some nodes to this queue.
    pq.push(new Node(true , 2, "Dos"));
    pq.push(new Node(false, 3, "Tres"));
    pq.push(new Node(true , 4, "Quatro"));
    pq.push(new Node(false, 1, "Uno"));
    pq.push(new Node(true , 5, "Cinco"));
    
    // Print each node.
    cout << endl << "Printed priority queue: " << endl;
    int counter = 0;
    while(pq.empty() == false)
        {
        counter += 1;
        Node* thisnode = pq.top();
        pq.pop();
        cout << "Node " << counter << ": \tName: " << thisnode->name << " \tQuantity: " << thisnode->quant << endl;
        }
    
    return 0;
    }
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
////////// HASH MAP ////////////////////////////////////
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() 
    {
    cout << "C++ Hash Map Code" << endl;
    
    // Create an unordered_map
    unordered_map<string, int> m; // Map's a string key to an int value.
    
    // Add a few pairs to the map.
    m["Sit Still"] = 1;
    m["Look Pretty"] = 100;
    m["Starboy"] = 1000;
    m["Hotel Room"] = 295;
    
    // Iterate through the map using iterators.
    cout << "Printing map using iterators: " << endl;
    unordered_map<string, int>::iterator it = m.begin();
    while(it != m.end())
        {
        cout << it->first << ": " << it->second << endl;
        it++;
        }
    cout << endl;
    
    // The ordering of the iterator above is random. 
    
    // Check if a key exists.
    if(m.find("Taylor Swift") == m.end()) // Checks entire map...not very efficient.
        {
        cout << "Correctly did not find Taylor Swift in our map." << endl;
        }
    
    cout << m["Crooked Smile"] << endl; // Initializes the value for key="Crooked Smile" to 0.
    
    // To use a Node instead of a primitive data type, just replace int with the Node. 
    // It won't affect any operations. (AKA we don't need to do anything special.)
    
    return 0;
    }
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
////////// SET ////////////////////////////////////
#include <iostream>
#include <set>

using namespace std;

int main() 
    {
    cout << "C++ Set Code" << endl;
    
    // Sets are data structures that don't contain duplicates.
    
    // Create a set
    set<int> myset;
    
    // Insert some numbers into the set. 
    myset.insert(3);
    myset.insert(2);
    myset.insert(2);
    myset.insert(4);
    myset.insert(1);
    
    // Print each number in the set.
    cout << "Printing the numbers in the set: " << endl;
    set<int>::iterator it = myset.begin();
    while(it != myset.end())
        {
        cout << *it << " ";
        it++;
        }
    cout << endl;
    
    // Remove an item from the set.
    myset.erase(2);
    
    // Check if a specific number is in the set
    if(myset.find(2) == myset.end())
        {
        cout << "2 is no longer in the set." << endl;
        }
 
    return 0;
    }
///////////////////////////////////////////////////////