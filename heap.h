#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> data;
  int n;
  PComparator comp;
	

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  n = m;
  comp = c;

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{    }

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

		throw std::underflow_error("empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return data[0];


}



// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("empty");

  }

	T& last = data[size() - 1];
	T& top = data[0];
	
  std::swap(top, last);
	data.pop_back();

	std::size_t index = 0;

	while (index * n + 1 < size()) 
	{
		//T& top = data[index];
		
    //Iterates through other children of top to find best comp
		int compIndex = index * n + 1;
    for(int i = 2; i <= n; i++)
    {
      //std::cout << index * n + i << "_vs_" << data.size() - 1 << std::endl;
      if(index * n + i > data.size() - 1)
      {
        //std::cout << "break!" << std::endl;
        break;
      }
      
      if(comp(data[index * n + i], data[compIndex]))
		  {
        compIndex = index * n + i;
      }
    }
    
		//T& compVal = data[compIndex];

		//Compare with "top" child
		if(comp(data[compIndex], data[index]))
		{
			std::swap(data[index], data[compIndex]);
		}
		else
		{
			break;
		}
		
    index = compIndex;

  }

  //for(unsigned int i = 0; i < data.size(); i++)
  //{
    //std::cout << data[i] << std::endl;
  //}

  //std::cout << std::endl;
		

}

template <typename T, typename PComparator>
std::size_t Heap<T,PComparator>::size() const {
    return data.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
    return data.size() == 0;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / n;
        T& current = data[index];
        T& parent = data[parent_index];
        if (comp(parent,current)) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;


    }
  
  /*for(unsigned int i = 0; i < data.size(); i++)
  {
    std::cout << data[i] << std::endl;
  }

  std::cout << std::endl;
  */


}




#endif

