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

		    ~ListArray(){
			    delete[] arr;
		    }

		    T operator[](int pos){
			    if(pos < 0 || pos > n){
		     		throw out_of_range("Fuera de rango");
        		    }
			    else{
		     		return arr[pos];
		    	    }
		    }


		    friend ostream& operator<<(ostream &out, const ListArray<T> &list){
        		    out << " " << list.n << " "  << endl;
			    for(int i = 0; i < list.n; i++){
				    out << "[" << list.get(i) << "] ";
			    }
			    out << endl; 
	                    return out;
		    }


		    void insert(int pos, T e){
			    if(pos >= 0 && pos <= n){
				for(int i = n; i >= pos+1; i--){
			    	arr[i] = arr[i-1];
			    	}
			    n++;
			    arr[pos] = e;
			    }
			    else{
				throw out_of_range("Fuera de rango");
			    }
		    }
		    void append(T e){
			    if(n >= max){
				    resize(n+1);
			    }	
			    insert(n , e);
		    }
		    void prepend(T e){
			    if(n >= max-1){
				    resize(n+1);
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
				        for(int i = pos; i <= n; i++){
					       aux[i] = arr[i+1];
					}
				}
				T num = arr[pos];
				delete[] arr;
				arr = aux;
				n = n - 1;
				return num;
		            }    
			    else{
				throw out_of_range("Fuera de rango");
			    }	
		    }

		    T get(int pos) const override{
			    if(pos >= 0 && pos < n){
				return arr[pos];
			    }
			    else{
				throw out_of_range("Fuera de rango");
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
