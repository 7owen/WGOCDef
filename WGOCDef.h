//
//  WGOCDef.h
//
//
//  Created by 7owen on 13-4-11.
//
//

#define fequal(a,b) (fabs((a) - (b)) < FLT_EPSILON)
#define fequalzero(a) (fabs(a) < FLT_EPSILON)
#define flessthan(a,b) (fabs(a) < fabs(b)+FLT_EPSILON)

#define RGBColor(r, g, b) [UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:1.f]

#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self

/*
 分辨率为pt，像素为真实pixel：
 
 1.iPhone5分辨率320x568，像素640x1136，@2x
 
 2.iPhone6分辨率375x667，像素750x1334，@2x
 
 3.iPhone6 Plus分辨率414x736，像素1242x2208，@3x，（注意，在这个分辨率下渲染后，图像等比降低pixel分辨率至1080p(1080x1920)
 */

#define is3_5InchScreen ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )480 ) < DBL_EPSILON )
#define is4InchScreen ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#define is4_7InchScreen ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )667 ) < DBL_EPSILON )
#define is5_5InchScreen ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )736 ) < DBL_EPSILON )

#define isPadDevice (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define isRetinaDevice ([[UIScreen mainScreen] respondsToSelector:@selector(scale)] && [UIScreen mainScreen].scale > 1)

#define CREATE_DIRECTORY_IFNEED(PATH) { \
    NSFileManager *fileManager = [NSFileManager defaultManager];    \
    if (![fileManager fileExistsAtPath:PATH]) {  \
        NSError *error = nil;   \
        if (![fileManager createDirectoryAtPath:PATH withIntermediateDirectories:YES attributes:nil error:&error]) { \
            CKLogError(@"%@",[error description]);   \
        }   \
    }   \
}

#define isIOS8Later ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define isIOS7Later ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define isIOS6Before ([[[UIDevice currentDevice] systemVersion] floatValue] < 6.0)

#define MAKESTRING(obj) #obj

#define perform_block_delay(delay, queue, block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), queue, block)
#define perform_block_main_delay(delay,block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), block)

#define __begin do {
#define __break break;
#define __finish }while(0);