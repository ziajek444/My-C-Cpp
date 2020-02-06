const unsigned int MAX_SESORS = 20;

/* sensor_w.c */
// write value into certain sensor. read data from input sensor struct
int write_sensor(const struct Sensor*, const int);

// write value into all sensors. read data from input sensors arr struc
int write_all_sensors(const struct Sensor*);


/* sensor_r.c */
// read one sensor. Save value of certain sensor to structure
int read_sensor(struct Sensor*, const int);

int read_all_sensors(struct Sensor*);

// prints content of one structure
int print_sensor(const int);

// prints content of all structures
int print_all_sensors();


/* sensor_l.c */
// prints whole local structure
void print_local_db(const struct Sensor[20]);

// prints certain local structure
void print_single_local_db(const struct Sensor, const int);


/* sensor_i.c */
// deallocate process
void closeDB();

// init process
void initDB();

// --------- not for casual users ---------------------
// DEBUD Purpose !

// shared memory content prints (not for casual users)
void SHCONTENT();

// shared memory content clear (not for casual users)
void SHCLEAR();
