#ifndef SLL_H
#define SLL_H

template <class T> class SLListNode;
template <class T> class SLList;

template <class T>
class SLListNode{
    friend class SLList<T>;
    public:
        SLListNode(T data_=0, SLListNode<T>* link_=NULL)
        {data=data_; link=link_;};

    private:
        T data;
        SLListNode<T> *link;
};


template <class T>
class SLList{
    public:
        SLList(){first=NULL; length=0;};
        ~SLList(){};

        int Length() const;
        void Display();

        void InsertNodeIndex(int idx, const T& element);
        int Search(const T& element);
        void DeleteNodeIndex(int idx);
        void DeleteNodeValue(const T& element);
        void Reverse();

    private:
        SLListNode<T>* first;
        int length;
};


template <class T>
int SLList<T>::Length() const{
    return(length);
};


template <class T>
void SLList<T>::Display()
{
    SLListNode<T>*temp = first;
    std::cout<<"SLList: ";
    while(temp != NULL){
        std::cout<<"["<<temp->data<<"]";
        temp=temp->link;
    }
    std::cout<<"\n";
}

//////////////////////////////////////////////////
////////// DO NOT TOUCH ANYTHING ABOVE! //////////
//////////////////////////////////////////////////

template <class T>
void SLList<T>::InsertNodeIndex(int idx, const T& element){
////////// Fill in your own code here

};

template <class T>
int SLList<T>::Search(const T& element)
{
////////// Fill in your own code here
};


template <class T>
void SLList<T>::DeleteNodeIndex(int idx)
{
////////// Fill in your own code here
};

template <class T>
void SLList<T>::DeleteNodeValue(const T& element)
{
////////// Fill in your own code here
};

template <class T>
void SLList<T>::Reverse()
{
////////// Fill in your own code here
};






#endif // SLL_H
