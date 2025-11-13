#include <iostream>
#include <vector>
#include "Queue.h"
#include "SearchSort.h"
using namespace std;

// Forward declarations for functions defined in SearchSort.*
// Adjust signatures if your SearchSort.h uses different names/signatures.
template<typename T>
void insertion_sort_queue(Queue<T>& q);

int linear_search_last(const std::vector<int>& arr, int target, int index);

int main() {
    Queue<int> q;
    vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int choice;

    while (true) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Push 10 integers into Queue\n";
        cout << "2. Display Queue\n";
        cout << "3. Move front element to rear\n";
        cout << "4. Recursive Linear Search (Last Occurrence)\n";
        cout << "5. Sort Queue (Insertion Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 1; i <= 10; i++) q.push(i);
            cout << "Pushed 10 integers into queue.\n";
            break;
        case 2:
            cout << "Queue elements: ";
            q.display();
            break;
        case 3:
            q.move_to_rear();
            cout << "Moved front element to rear.\n";
            q.display();
            break;
        case 4: {
            cout << "Vector contents: ";
            for (int x : vec) cout << x << " ";
            cout << endl;
            int target;
            cout << "Enter target to find last occurrence: ";
            cin >> target;
            int pos = linear_search_last(vec, target, 0);
            if (pos == -1)
                cout << "Target not found.\n";
            else
                cout << "Last occurrence at index: " << pos << endl;
            break;
        }
        case 5:
            cout << "Sorting queue...\n";
            insertion_sort_queue(q);
            cout << "Queue after sorting: ";
            q.display();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
