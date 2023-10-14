/*
    1. Creating Min-Stack with all operation in O(1)
    2. We maintain two vectors.
    3. Vector A stores the stack 
    4. Vector B stores the minimum till the current element
    5. By stoing the running minimum in vector B, we can getMin in O(1)
    6. Use *rbegin of B and A to get the minimum and top element
*/

class minStack
{
    
    vector<int> a;
    vector<int> b;
    
	public:
		
		minStack() 
		{ 
            a = {};
            b = {};
		}
		
		void push(int num)
		{
            a.push_back(num);
            if(b.empty())
                b.push_back(num);
            else
            {
                int newMin;
                newMin = min(num,*b.rbegin());
                b.push_back(newMin);
            }
		}
		
		int pop()
		{
            if(a.size())
            {
                int top = *a.rbegin();
                a.pop_back();
                b.pop_back();    
                return top;
            }
            else
                return -1;
            
		}
		
		int top()
		{
            if(a.size())
                return *a.rbegin();
            else
                return -1;
		}
		
		int getMin()
		{
            if(b.size())
                return *b.rbegin();
            else
                return -1;
		}
};
