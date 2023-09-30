#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	    private:
		     Node<T>* first;
		     int n;

	    public:
		     ListLinked() : first(nullptr){
			    n = 0;
		     }
		     ~ListLinked(){
			     while(first != nullptr){
			     Node<T>* aux = first->next;
			     delete first;
			     first = aux;
			     }
		     }
		     T operator[](int pos){
			     if(pos < 0 || pos >= n){
				     throw std::out_of_range("Fuera de rango");
			     }
			     else{
				     Node<T>* aux = first;
				     for(int i = 0; i != pos; i++){
					     aux = aux->next;
				     }
				     return aux->data;
			     }
		     }
		     friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			     out << list.n << std::endl;
			     return out;
		     }
		     void insert(int pos, T e){
			     if(pos >= 0 && pos <= n){
				     switch (pos){
					     case 0:
	                                        first = new Node(e,first->next);
						break;
					     case size():
						Node<T>* aux = first;
					        Node<T>* preaux = aux;
						for(int i = 0; i < pos; i++){
						     preaux = aux;
						     aux = aux->next;
						}
						aux = new Node(e, nullptr);
						preaux->next = aux;
						break;
                                             default:
				     	        aux = first;
				     	        preaux = aux;
				     	     	for(int i = 0; i < pos; i++){
					     	     preaux = aux;
					     	     aux = aux->next;
				     	     	}
				     	     	preaux->next = new Node(e, aux);
					     	break;
				     }
		                     n++;
			     }
			     else{
				     throw std::out_of_range("Fuera de rango");
			     }
		     }
		     void append(T e){
			     insert(n, e);
		     }
		     void prepend(T e ){
			     insert(0, e);
		     }
		     T remove(int pos){
			     if(pos >= 0 && pos < n){
				     switch (pos){
					  case 0:
				     		Node<T>* aux = first;
						first = aux->next;
						T num = aux->data;
						delete aux;
						return num;
						break;
					  case size()-1:
					        aux = first;
					        Node<T>* preaux = aux;
				     		for(int i = 0; i < pos; i++){
							preaux = aux;
							aux = aux->next;
						}
						preaux->next = nullptr;
						num = aux->data;
						delete aux;
						return num;
						break;
					  default:
						aux = first;
						preaux = aux;
						for(int i = 0;i < pos; i++){
							preaux = aux;
							aux = aux->next;
						}
						preaux->next = aux->next;
						num = aux->data;
						delete aux;
						return num;
						break;
				     }
				     n--;
			     }
			     else{
				     throw std::out_of_range("Fuera de rango");
			     }
		     }
		     T get(int pos){
			     if(pos >= 0 && pos < n){
				     Node<T>* aux = first; 
				     for(int i; i < pos; i++){
					     aux = aux->next;
				     }
				     return aux->data;
			     }
			     else{
				     throw std::out_of_range("Fuera de rango");
			     }
		     }
		     int search(T e){
			     Node<T>* aux = first;
			     for(int i = 0; i < n; i++){
				     if(aux->data == e){
					     return i;
				     }
				     else{
					     aux = aux->next;
				     }
			     }
		             return -1;
			     
		     }
		     bool empty(){
			     return n == 0;
		     }
		     int size(){
			     return n;
		     }
};
		     
