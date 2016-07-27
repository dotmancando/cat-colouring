//
//  const.h
//  catColorTest
//
//  Created by Nitipak Samsen on 27/07/2016.
//
//

#ifndef const_h
#define const_h

using namespace std;

//const int APP_WIDTH = 1920;
//const int APP_HEIGHT = 1080;
const int APP_WIDTH = 1440;
const int APP_HEIGHT = 810;

const bool READ_KINECT_FROM_FILE = true;
const bool SERVER_ONLY = false; // no kinect no cat
const string SERVER_ADDRESS = "localhost";

const string PRODUCTION_FOLDER = "/Users/dotmancando/Google Drive/photos/trumpington_production/"; // change this to the location on your machine
//const string PRODUCTION_FOLDER = "/Users/trumpingtoncat/Google Drive/photos/trumpington_production/"; // change this to the location on your machine

//const string KINECT_PICTURE_FOLDER = PRODUCTION_FOLDER + "kinect_image/finalSetup14/";
const string KINECT_PICTURE_FOLDER = PRODUCTION_FOLDER + "kinect_image/finalSetup14_legless/";
//const string CAT_PICTURE_FOLDER = PRODUCTION_FOLDER + "cat_image/";

const string CAT_PICTURE_FOLDER = "/Volumes/cat_image/cat_image/";

const string DEPTH_NAME = "image_depth";
const string REGISTERED_NAME = "image_rgb";
const string RGB_NAME = "image_RGB_";

const int CAT_STATE_NUM = 14;
const string CAT_STATE_NAME[CAT_STATE_NUM] {
    "SLEEPING", "SLEEP_OVER", "LYING", "SIT_UP", "SITTING", "STAND_UP", "STANDING", "WALKING", "PORTAL",
    "NOT_HERE",
    "RUNNING_SIDEWAY", "AT_CANTEEN",
    "WALL_PORTAL", "PORTAL_GUARDING"
};


const string CAT_STATE_FOLDER_NAME[10] {
    "0_SLEEPING/", "1_SLEEP_OVER/", "2_LYING/", "3_SIT_UP/", "4_SITTING/", "5_STAND_UP/", "6_STANDING/", "7_WALKING/", "8_PORTAL/",
    "9_NOT_HERE/"};

enum CAT_STATE {
    SLEEPING = 0, SLEEP_OVER = 1, LYING = 2, SIT_UP = 3, SITTING = 4, STAND_UP = 5, STANDING = 6, WALKING = 7, PORTAL = 8,
    NOT_HERE = 9,
    RUNNING_SIDEWAY = 10, AT_CANTEEN = 11,
    WALL_PORTAL = 12, PORTAL_GUARDING = 13
};
//  lets add 2 states for screen saver, 10 running across, 12 side portal

// 10 running, depends on the desiredState, chose direction and exit goal
// 11 at_canteen


// 12 enter_side_portal, depends on desiredState, chose animation
// 13 waiting



//const int CAT_COLOUR_NUM = 4;


const int CAT_ACCESSORY_NUM = 8;
const string CAT_ACCESSORY_NAME[CAT_ACCESSORY_NUM] { "hat0", "hat1", "hat2", "hat3", "hat4", "hat5", "hat6", "hat7"};


const int CAT_ANIMATION_STEP = 2;
enum EASTER_EGGS { NOTHING = 0, SOMETHING1 = 1, SOMETHING2 = 2, SOMETHING3 = 3, SOMETHING4 = 4};


const int KINECT_PICTURE_FRAMERATE = 15;


const string MACHINE_ID = "OF_CAT";

const int SERVER_PORT = 5000;
const int SERVER_ATTEMP_INTERVAL = 3000;



const int KINECT_MERGED_WIDTH = 1920;
const int KINECT_MERGED_HEIGHT = 1458;

const int KINECT_DEPTH_WIDTH = 512;
const int KINECT_DEPTH_HEIGHT = 424;
const int NEAREST_POINT_STEP = 3;
const int NEAREST_POINT_WIDTH = KINECT_DEPTH_WIDTH / NEAREST_POINT_STEP;
const int NEAREST_POINT_HEIGHT = ( KINECT_DEPTH_HEIGHT - (KINECT_DEPTH_HEIGHT/4) ) / NEAREST_POINT_STEP;

const int KINECT_RGB_WIDTH = 1920;
const int KINECT_RGB_HEIGHT = 1080;

const int KINECT_REGISTERED_WIDTH = 1024;
const int KINECT_REGISTERED_HEIGHT = 848;

const string CAT_DEFAULT_ANIMATION = "4_SITTING/paw_licking";
const int CAT_DEFAULT_DESIRED_STATE = SITTING;
const int CAT_DEFAULT_CURRENT_STATE = CAT_DEFAULT_DESIRED_STATE;

//const int CAT_SCALE = 2;

const int CAT_IMAGE_WIDTH = 960;
const int CAT_IMAGE_HEIGHT = 540;
const float CAT_IMAGE_BLANK_PROPORTION = 0.11; // a portion at the bottom of the image that is blank. (actual is 0.13)
const float CAT_DEFAULT_HEIGHT = 320;
const float CAT_DEFAULT_HEIGHT_JUMP = 180.0;

const int CAT_DEFAULT_LYING_HEIGTH = 140;
const int CAT_DEFAULT_LYING_LENGTH = 300;
const int CAT_DEFAULT_LYING_WIDTH[9] {0, 130, 270, 380, 270, 270, 380, 270}; // width of the cat in each camera, the first value is dummy

const int CAT_DEFAULT_SITTING_HEIGTH = 320;
const int CAT_DEFAULT_SITTING_LENGTH = 140;
const int CAT_DEFAULT_SITTING_WIDTH[9] {0, 130, 180, 220, 180, 130, 180, 220, 180}; // width of the cat in each camera, the first value is dummy

const int CAT_DEFAULT_STANDING_HEIGTH = 240;
const int CAT_DEFAULT_STANDING_LENGTH = 360;
const int CAT_DEFAULT_STANDING_WIDTH[9] {0, 130, 270, 380, 270, 130, 270, 380, 270}; // width of the cat in each camera, the first value is dummy

const int CAT_MIN_HEIGHT = 80;
const int CAT_MAX_HEIGHT = 250;

//const int CAT_DEFAULT_WALK_SPEED = 600;
const float CAT_DEFAULT_WALK_SPEED = 12.0;
const float CAT_DEFAULT_RUN_SPEED = 80.0;
const int CAT_DEFAULT_STATE_CHANGE_INTERVAl = 30000;

enum APP_STATE { SETUP_KINECT = 0, SETUP_SPACE = 1, PERFORMANCE = 2};
const string APP_STATE_NAME[3] { "SETUP_KINECT", "SETUP_SPACE", "PERFORMANCE"};


enum DISTANCE_TYPE { FAR = 0, APPROACHING = 1, TOUCHING = 2, THROUGH = 3};
enum CAT_POSE { LYING_POSE = 0, SITTING_POSE = 1, STANDING_POSE = 2};

const int FOLDER_NUMBER = 24;
const int HAT_NUMBER = 8;
const int CAMERA_NUMBER = 8;
const string FOLDER_NAME[FOLDER_NUMBER] {
    "0_SLEEPING/sleep_on_side", "0_SLEEPING/sleep_walking",
    "1_SLEEP_OVER/sleep_over",
    "2_LYING/sleeping", "2_LYING/sleeping_really", "2_LYING/yawning",
    "3_SIT_UP/sit_up",
    "4_SITTING/meowing", "4_SITTING/paw_licking", "4_SITTING/play_with_low_toy", "4_SITTING/play_with_toy",
    "4_SITTING/scratching_itself","4_SITTING/scratching_post", "4_SITTING/staring", "4_SITTING/tail_chase",
    "5_STAND_UP/sit_to_stand",
    "6_STANDING/catch_laser", "6_STANDING/jump_upward", "6_STANDING/stand_idle", "6_STANDING/stretching",
    "7_WALKING/run", "7_WALKING/walking",
    "8_PORTAL/enter_through_portal", "8_PORTAL/exit_through_portal"
};

const int MAX_GLITCH_COUNTER = 80;

const string BLENDMODE_NAME[6] = {"OF_BLENDMODE_DISABLED", "OF_BLENDMODE_ALPHA", "OF_BLENDMODE_ADD", "OF_BLENDMODE_SUBTRACT", "OF_BLENDMODE_MULTIPLY", "OF_BLENDMODE_SCREEN"};


#endif /* const_h */
