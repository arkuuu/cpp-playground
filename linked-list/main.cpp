#include <iostream>

template <class T>
struct Node
{
    T value = 0;
    Node<T> *next = nullptr;
};

template <class T>
class LinkedList
{
public:
    void add(const T &value)
    {
        auto *node = new Node<T>;
        node->value = value;
        node->next = head;
        head = node;
    }

    void remove(const T &value)
    {
        auto *current = head;
        Node<T> *previous = nullptr;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                // TODO Improve code if value to remove is first
                // node in list, is there a simpler solution?
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;

                // TODO What if there are multiple nodes with the
                // value which should be removed? Right now only the
                // first one will be removed.
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void print()
    {
        auto *current = head;
        while (current != nullptr)
        {
            std::cout << current->value << std::endl;
            current = current->next;
        }

        std::cout << std::endl;
    }

private:
    Node<T> *head = nullptr;
};

int main()
{
    LinkedList<int> list;
    list.add(10);
    list.add(5);
    list.add(2);
    list.add(6);
    list.print();

    // Remove some node
    list.remove(5);
    list.print();

    // Remove node and end of list
    list.remove(10);
    list.print();

    // Remove node at beginning of list
    list.remove(6);
    list.print();
}
