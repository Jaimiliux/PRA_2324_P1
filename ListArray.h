#include <ostream>
#include "List.h"
#include <stdexcept>
using namespace std;
template <typename T> 
class ListArray : public List<T> {

	    private:

		    T* arr;
	            int max;
		    int n; 
		    static const int MINSIZE = 2;

		    void resize(int new_size){
			    T* aux = new T[new_size];
			    for(int i = 0; i < size(); i++){
				    aux[i] = arr[i]; 
			    }
			    delete[] arr;
			    arr = aux;
			    max = new_size;

		    }
			    
	    public:
	            
		    ListArray() : arr(nullptr), max(MINSIZE), n(0){
			     arr = new T[MINSIZE];
		    }

		    ~ListArray();

		    T operator[](int pos){
			    if(pos < 0 || pos >= size()){
					throw out_of_range();
				    }
			    else{
					return arr[pos];
				    }
		    }

		    friend ostream& operator<<(ostream &out, const ListArray<T> &list){
			    out << list->arr << "\n" << list.max << "\n" << list.n << "\n" << list.MINSIZE << endl;
			    return out;
		    }

		    void insert(int pos, T e){
			    if(pos >= 0 && pos <= size()){
			    	arr[pos] = e;
			    }
			    else{
				throw out_of_range();
			    }
			    size() = size() + 1;

		    }
		    void append(T e){
			    insert(size() , e);
		    }
		    void prepend(T e){
			    for( int i = 0; i < size(); i++){
				arr[i+1]= arr[i];
			    }
	    		    insert( 0 , e);
		    }

		    T remove(int pos){
			    if(pos >= 0 && pos < size()){
				T* aux = new T[sizeof(arr)];
				for(int i = 0; i < pos; i++){
	  				aux[i] = arr[i];
				}
				if( pos == size() - 1){
					;
				}
				else{
				for(int i = pos; i < size() - 1; i++){
					aux[i] = arr[i+1];
					}
				}
				T num = arr[pos];
				delete[] arr;
				arr = aux;
				size() = size() - 1;
				return num;
		            }    
			    else{
				throw out_of_range();
			    }	
		    }

		    T get(int pos){
			    if(pos > 0 && pos < size()){
				return arr[pos];
			    }
			    else{
				throw out_of_range();
			    }
		    }
		    int search(T e){
			    int i = 0;
			    while(i < size() && e != arr[i]){
				    i++;
			    }
			    if(i == size()){
				    return -1;
			    }
			    else{
				    return i;
			    }
		    }
		    bool empty(){
			    return n == 0;

		    }
		    int size(){
			    return n;
		    }


                                        

		
						 
			     


};
