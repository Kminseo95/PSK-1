#BITMAP
{
JGLEE__LED_RECT_GREEN.bmp
0 0 22 22
0
}
#DYNAMIC
{
IF_OR: (dCH != dSts)
VIS 1
}
#BITMAP
{
JGLEE__LED_RECT_GRAY.bmp
0 0 22 22
0
}
#DYNAMIC
{
IF_OR: (dCH == dSts)
VIS 1
}