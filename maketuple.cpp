#include <iostream>
#include <tuple>
#include <functional>
using namespace std; 
 
int main()
{
    auto emp_details = std::make_tuple(95007501, "Ganesh Samarthyam", "27/07/1978", true);
    std::cout << "The employee details are: " << endl 
              << "Roll no: " << get<0>(emp_details) << endl  
              << "Emp name: " << get<1>(emp_details) << endl  
              << "DOB: " << get<2>(emp_details) << endl
              << "Permanent employee: " << get<3>(emp_details) << endl; 

    long emp_no; 
    string emp_name; 
    string emp_dob; 
    bool emp_is_permanent;  
    tie(emp_no, emp_name, emp_dob, emp_is_permanent) = emp_details;
    cout << emp_no << " " << emp_name << " " << emp_dob << " " << emp_is_permanent << "\n";
}
