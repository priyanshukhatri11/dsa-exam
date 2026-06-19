#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insert()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    int p = i + 1;

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

void merge(int arr[], int l, int m, int r)
{
    int temp[100];
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (int x = l; x <= r; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1.Insert Linked List";
        cout << "\n2.Display Linked List";
        cout << "\n3.Merge Sort";
        cout << "\n4.Quick Sort";
        cout << "\n5.Binary Search";
        cout << "\n6.Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            insert();
        }

        else if (choice == 2)
        {
            display();
        }

        else if (choice == 3 || choice == 4 || choice == 5)
        {
            int n;
            cout << "Enter size: ";
            cin >> n;

            int arr[100];

            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            if (choice == 3)
            {
                mergeSort(arr, 0, n - 1);

                cout << "Sorted Array: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
            }

            else if (choice == 4)
            {
                quickSort(arr, 0, n - 1);

                cout << "Sorted Array: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
            }

            else
            {
                int key;
                cout << "Enter value to search: ";
                cin >> key;

                int pos = binarySearch(arr, n, key);

                if (pos == -1)
                    cout << "Not Found";
                else
                    cout << "Found at Position " << pos + 1;
            }

            cout << endl;
        }

    } while (choice != 6);

    return 0;
}