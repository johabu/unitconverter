#ifndef UNITCONVUNITS
#define UNITCONVUNITS
#include <stdlib.h>

char *Error_types[] = {"Error - Unknown quantity!","Error - Not available!","Error - Unknown unit!","Error in prompt - Please restart the program!"};

char *Quantities[] = {"Length","Area","Volume","Time","Temperature"};

char *Units_short[5][16] = {
	{"cm","dm","m","km","mm","um","nm","yd","ft","in","mi","NM"},
	{"mm2","cm2","dm2","m2","a","ha","km2","yd2","ft2","in2","mi2","ac"},
	{"mm3","cm3","dm3","m3","km3","ml","cl","dl","l","hl","yd3","ft3","in3","gal1","gal2","gal3"},
	{"ns","us","ms","s","min","h","day","week","yr"},
	{"C","F","K"},
	};

char *Units_long[5][16] = {
	{"cm (centimetre)","dm (decimetre)","m  (metre)","km (kilometre)","mm (millimetre)","um (micrometre)","nm (nanometre)","yd (yard)","ft (foot)","in (inch)","mi (mile)","NM (nautic mile)"},
	{"mm2 (square millimetre)","cm2 (square centimetre)","dm2 (square decimetre)","m2  (square metre)","a   (are)","ha  (hectare)","km2 (square kilometre)","yd2 (square yard)","ft2 (square feet)","in2 (square inch)","mi2 (square mile)","ac  (acre)"},
	{"mm3 (cubic millimetre)","cm3 (cubic centimetre)","dm3 (cubic decimetre)","m3  (cubic metre)","km3 (cubic kilometre)","ml  (millilitre)","cl  (centilitre)","dl  (decilitre","l   (litre)","hl  (hectolitre)","yd3 (cubic yard)","ft3 (cubic feet)","in3 (cubic inch)","gal1 (Imperial gallon)","gal2 (US liquid gallon)","gal3 (US dry gallon)"},
	{"ns  (nanosecond)","us  (microsecond)","ms  (millisecond)","s   (second)","min (minute)","h   (hour)","day","week","yr  (year)"},
	{"C (degree Celsius)","F (degree Fahrenheit)","K (Kelvin)"},
	};

int Quantity_units_num[] = {12,12,16,9,3};

double Length_factors[12][12] = { 
	{1,0.1,0.01,0.00001,10,10000,10000000,0.01093613,0.032808,0.3937008,0.00000621371,0.00000539957},
	{10,1,0.1,0.0001,100,100000,100000000,0.1093613,0.32808,3.937008,0.0000621371,0.0000539957},
	{100,10,1,0.001,1000,1000000,1000000000,1.093613,3.2808,39.37008,0.000621371,0.000539957},
	{100000,10000,1000,1,1000000,1000000000,1000000000000ll,1093.613,3280.8,39370.08,0.621371,0.539957},
	{0.1,0.01,0.001,0.000001,1,1000,1000000,0.001093613,0.0032808,0.03937008,0.000000621371,0.000000539957},
	{0.0001,0.00001,0.000001,0.000000001,0.001,1,10000.000001093613,0.0000032808,0.00003937008,0.000000000621371,0.0000000006231371,0.000000000539957},
	{0.0000001,0.00000001,0.000000001,0.000000000001,0.000001,0.001,1,0.000000001093613,0.0000000032808,0.00000003937008,0.000000000000621371,0.000000000000539957},
	{91.44,9.144,0.9144,0.0009144,914.4,914400,914400000,1,3,36,0.000568182,0.000493737},
	{30.48,3.048,0.3048,0.0003048,304.8,304800,304800000,0.3333333333,1,12,0.000189394,0.000164579},
	{2.54,0.254,0.0254,0.0000254,25.4,25400,25400000,0.2777777778,0.083333333333,1,0.0000157828,0.0000137149},
	{160934.4,16093.44,1609.344,1.609344,1609344,1609344000,1609344000000ll,1760,5280,63360,1,0.868976},
	{185200,18520,1852,1.852,1852000,1852000000,1852000000000ll,2025.372,6076.115,7291339,1.150779,1},
	};
double Area_factors[12][12] = {
	{1,0.01,0.0001,0.000001,0.00000001,0.0000000001,0.000000000001,0.00000119599,0.0000107639,0.001550003,0.0000000000003861022,0.0000000002471053815},
	{100,1,0.01,0.0001,0.000001,0.00000001,0.0000000001,0.000119599,0.00107639,0.1550003,0.00000000003861022,0.00000002471053815},
	{10000,100,1,0.01,0.0001,0.000001,0.00000001,0.0119599,0.107639,15.50003,0.00000003861022,0.000002471053815},
	{1000000,10000,100,1,0.01,0.0001,0.000001,1.19599,10.7639,1550.003,0.0000003861022,0.0002471053815},
	{100000000,1000000,10000,100,1,0.01,0.0001,119.599,1076.39,155000.3,0.00003861022,0.02471053815},
	{10000000000ll,100000000,1000000,10000,100,1,0.01,11959.9,107639,15500030,0.003861022,2.471053815},
	{1000000000000ll,10000000000ll,100000000,1000000,10000,100,1,1195990,10763900,1550003000ll,0.3861022,247.1053815},
	{836127.39237,8361.2739237,83.612739237,0.83612739237,0.0083612739237,0.000083612739237,0.00000083612739237,1,9,1295.9999666,0.00000032283062567,0.0002066115702},
	{92903.043597,929.03043597,9.2903043597,0.092903043597,0.00092903043597,0.0000092903043597,0.000000092903043597,0.1111111111,1,143.99999628,0.000000035870069519,0.00002295684114},
	{645.16004163,6.4516004163,0.064516004163,0.00064516004163,0.0000064516004163,0.000000064516004163,0.00000000064516004163,0.000771605,0.0069444446,1,0.00000000024909771142,0.000000159422512},
	{2589987832200ll,25899878322ll,258998783.22,2589987.8322,25899.878322,285.99878322,2.5899878322,3097599.5475,27878395.927,4014488909.9F,1,640},
	{4046856422.4,40468564.224,404685.64224,4046.8564224,40.468564224,0.40468564224,0.0040468564224,4840,43560,6272639.8381,0.0015625,1},
	};
double Volume_factors[16][16] = {
	{1,0.001,0.000001,0.000000001,0.000000000000000001,0.001,0.0001,0.00001,0.000001,0.00000001,0.000000001307951,0.00000003531468,0.00006102376,0.0000002199688,0.0000002641722,0.0000002270208},
	{1000,1,0.001,0.000001,0.000000000000001,1,0.1,0.01,0.001,0.00001,0.000001307951,0.00003531468,0.06102376,0.0002199688,0.0002641722,0.0002270208},
	{1000000,1000,1,0.000000000001,1000,100,10,1,0.01,0.001307951,0.03531468,61.02376,0.2199688,0.2641722,0.2270208},
	{1000000000,1000000,1000,1,0.0000000001,1000000,100000,10000,1000,10,1.307951,35.31468,61023.76,219.9688,264.1722,227.0208},
	{1000000000000000000ll,1000000000000000ll,1000000000000ll,1000000000,1,1000000000000000ll,100000000000000ll,10000000000000ll,1000000000000ll,10000000000ll,1307951000,35314680000ll,61023760000000ll,21968800000ll,264172200000ll,227020800000ll},
	{1000,1,0.001,0.000001,0.000000000000001,1,0.1,0.01,0.001,0.00001,0.000001307951,0.00003531468,0.06102376,0.0002199688,0.0002641722,0.0002270208},
	{10000,10,0.01,0.00001,0.00000000000001,10,1,0.1,0.01,0.0001,0.00001307951,0.0003531468,0.6102376,0.002199688,0.002641722,0.002270208},
	{100000,100,0.1,0.0001,0.0000000000001,100,10,1,0.1,0.001,0.0001307951,0.003531468,6.102376,0.02199688,0.02641722,0.02270208},
	{1000000,1000,1,0.000000000001,1000,100,10,1,0.01,0.001307951,0.03531468,61.02376,0.219688,0.2641722,0.2270208},
	{100000000,100000,100,0.1,0.0000000001,100000,10000,1000,100,1,0.1307951,3.531468,6102.376,21.99688,26.41722,22.70208},
	{764554635.5,764554.6355,764.5546355,0.7645546355,0.0000000007645546355,764554.6355,76455.46355,7645.546355,764.5546355,7.645546355,1,27,46656,168.1781657,201.97408007,173.56980499},
	{28316835.94,28316.83594,28.31683594,0.02831683594,0.00000000002831683594,28316.83594,2831.683594,283.1683594,28.31683594,0.2831683594,0.037037037,1,1728,6.2288204226,7.4805208486,6.4285107496},
	{16387.0597,16.3870597,0.0163870597,0.0000163870597,0.00000000000000163870597,16.3870597,1.63870597,0.163870597,0.0163870597,0.000163870597,0.0000017008965,0.0005787037694,1,0.0036046419,0.0043290056,0.0037202034},
	{4546099.365,4546.099365,4.546099365,0.004546099365,0.000000000004546099365,4546099.365,454.6099365,45.46099365,4.546099365,0.04546099365,0.0059460751,0.1605440408,277.42007048,1,1.2009530442,1.032059092},
	{3785409.6684,3785.4096684,3.7854096684,0.0037854096684,0.0000000000037854096684,3785.4096684,378.54096684,37.854096684,3.7854096684,0.037854096684,0.0049511304,0.1336805311,231,0.8326720223,1,0.8593667312},
	{4404882.744,4404.882744,4.404882744,0.004404882744,0.000000000004404882744,4404.882744,440.4882744,44.04882744,4.404882744,0.04404822744,0.0057615708,0.1555570238,268.8025062,0.968936767,1.16364756,1},
	};
double Time_factors[9][9] = {
	{1,0.001,0.000001,0.000000001,0.00000000001666667,0.0000000000002777778,0.0000000000000115740741,0.000000000000001653439153,0.000000000000000031709792},
	{1000,1,0.001,0.000001,0.00000001666667,0.0000000002777778,0.0000000000115740741,0.000000000001653439153,0.000000000000031709792},
	{1000000,1000,1,0.001,0.00001666667,0.0000002777778,0.0000000115740741,0.000000001653439153,0.000000000031709792},
	{1000000000,100000,1000,1,0.01666667,0.0002777778,0.0000115740741,0.000001653439153,0.000000031709792},
	{60000000000,60000000,60000,60,1,0.01666667,0.0006944444,0.00009920634921,0.000001902587519},
	{3600000000000,3600000000,3600000,3600,60,1,0.41666667,0.005952381,0.0001141552511},
	{86400000000000,86400000000,86400000,86400,1440,24,1,0.1428571429,0.002739726},
	{604800000000000,604800000000,604800000,604800,10080,168,7,1,0.0191780822},
	{31536000000000000,31563000000000,31536000000,31536000,525600,8760,365,52.14285714,1},
	};

#endif
