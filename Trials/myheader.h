#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

//Hello world function with some designs
void hello();
//fuction to print a line of chararcters
void println(char);
//find distance of two cordinates
int dxy(int , int , int , int);


template<typename T1>
class List
{

    public:
        const T1 & operator[](unsigned index);
        void append(const T1 & data);
        // We define this constructor to make sure that head_ is null-initialized.
        List() : head_(nullptr) { }

    private:
        class ListNode
        {
        public:
            const T1 & data;
            ListNode *next;
            ListNode(const T1 & data) : data(data), next(nullptr){}
            };

    ListNode *head_; //pointing head of the list
        //ListNode* _find(const T & data);
};

//just an a group of class for geometric shapes
namespace sh
{
    class Cube
    {
      public:// Public members:
        ~Cube();
        Cube();
        Cube(double l);
        Cube(const Cube&cp);
        Cube & operator=(const Cube  &cp); //Cube const & operator=(Cube const & cp); will also work cause it maintain the argumetn o be a constant any way
        void cout_();
        double getVolume();
        double getSurfaceArea();
        void setLength(double l);

      private: // Private members:
        double length_;
    };
}

#endif // MYHEADER_H_INCLUDED
