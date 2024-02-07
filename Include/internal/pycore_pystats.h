#ifndef Py_INTERNAL_PYSTATS_H
#define Py_INTERNAL_PYSTATS_H
#ifdef __cplusplus
extern "C" {
#endif

#ifndef Py_BUILD_CORE
#  error "this header requires Py_BUILD_CORE define"
#endif

#ifdef Py_STATS
extern void _Py_StatsOn(void);
extern void _Py_StatsOff(void);
extern void _Py_StatsClear(void);
void _Py_Stats_Maybe_Set_Depth(uint16_t depth);
extern int _Py_PrintSpecializationStats(int to_file);
#endif

#ifdef __cplusplus
}
#endif
#endif  // !Py_INTERNAL_PYSTATS_H
