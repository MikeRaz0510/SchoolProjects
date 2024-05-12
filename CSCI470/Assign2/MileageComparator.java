// *************************************************************************** 
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************

import java.util.Comparator;

public class MileageComparator implements Comparator<Destination>
{
    public int compare(Destination dest1, Destination dest2)
    {
        return dest2.getMiles() - dest1.getMiles();
    }
}