#include <iostream>
#include <xlnt/xlnt.hpp>
#include <vector>

int main()
{
    xlnt::workbook wb;
    wb.load("./res/a.xlsx");
    auto ws = wb.active_sheet();
    std::clog << "Processing spread sheet" << std::endl;
    std::clog << "Creating a single vector which stores the whole spread sheet" << std::endl;
    std::vector< std::vector<std::string> > theWholeSpreadSheet;
    for (auto row : ws.rows(false)) 
    { 
        std::clog << "Creating a fresh vector for just this row in the spread sheet" << std::endl;
	std::vector<std::string> aSingleRow;
	for (auto cell : row) 
	{ 
	    std::clog << "Adding this cell to the row" << std::endl;
	    aSingleRow.push_back(cell.to_string());
	}
	std::clog << "Adding this entire row to the vector which stores the whole spread sheet" << std::endl;
	theWholeSpreadSheet.push_back(aSingleRow);
    }
    std::clog << "Processing complete" << std::endl;
    std::clog << "Reading the vector and printing output to the screen" << std::endl;
    for (int rowInt = 0; rowInt < theWholeSpreadSheet.size(); rowInt++)
    {
        for (int colInt = 0; colInt < theWholeSpreadSheet.at(rowInt).size(); colInt++)
	{
	    std::cout << theWholeSpreadSheet.at(rowInt).at(colInt) << std::endl;
        }
    }
    return 0;
}
