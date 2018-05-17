//
//  FQAttributeString.h
//  FQAttributedStringDemo
//
//  Created by mac on 2018/5/17.
//  Copyright © 2018年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class FQAttributeString;

/**属性字符串区域***/
@interface FQAttributedStringRange : NSObject


-(FQAttributedStringRange*)setFont:(UIFont*)font;              //字体
-(FQAttributedStringRange*)setTextColor:(UIColor*)color;       //文字颜色
-(FQAttributedStringRange*)setBackgroundColor:(UIColor*)color; //背景色
-(FQAttributedStringRange*)setParagraphStyle:(NSParagraphStyle*)paragraphStyle;  //段落样式
-(FQAttributedStringRange*)setLigature:(BOOL)ligature;  //连体字符，好像没有什么作用
-(FQAttributedStringRange*)setKern:(CGFloat)kern; //字间距
-(FQAttributedStringRange*)setLineSpacing:(CGFloat)lineSpacing;   //行间距
-(FQAttributedStringRange*)setStrikethroughStyle:(int)strikethroughStyle;  //删除线
-(FQAttributedStringRange*)setStrikethroughColor:(UIColor*)StrikethroughColor NS_AVAILABLE_IOS(7_0);  //删除线颜色
-(FQAttributedStringRange*)setUnderlineStyle:(NSUnderlineStyle)underlineStyle; //下划线
-(FQAttributedStringRange*)setUnderlineColor:(UIColor*)underlineColor NS_AVAILABLE_IOS(7_0);  //下划线颜色
-(FQAttributedStringRange*)setShadow:(NSShadow*)shadow;                          //阴影
-(FQAttributedStringRange*)setTextEffect:(NSString*)textEffect NS_AVAILABLE_IOS(7_0);
-(FQAttributedStringRange*)setAttachment:(NSTextAttachment*)attachment NS_AVAILABLE_IOS(7_0); //将区域中的特殊字符: NSAttachmentCharacter,替换为attachement中指定的图片,这个来实现图片混排。
-(FQAttributedStringRange*)setLink:(NSURL*)url NS_AVAILABLE_IOS(7_0);   //设置区域内的文字点击后打开的链接
-(FQAttributedStringRange*)setBaselineOffset:(CGFloat)baselineOffset NS_AVAILABLE_IOS(7_0);  //设置基线的偏移量，正值为往上，负值为往下，可以用于控制UILabel的居顶或者居低显示
-(FQAttributedStringRange*)setObliqueness:(CGFloat)obliqueness NS_AVAILABLE_IOS(7_0);   //设置倾斜度
-(FQAttributedStringRange*)setExpansion:(CGFloat)expansion NS_AVAILABLE_IOS(7_0);  //压缩文字，正值为伸，负值为缩

-(FQAttributedStringRange*)setStrokeColor:(UIColor*)strokeColor;  //中空文字的颜色
-(FQAttributedStringRange*)setStrokeWidth:(CGFloat)strokeWidth;   //中空的线宽度


//可以设置多个属性
-(FQAttributedStringRange*)setAttributes:(NSDictionary*)dict;

//得到构建器
-(FQAttributeString *)builder;

@end

@interface FQAttributeString : NSObject


+(FQAttributeString*)builderWith:(NSString*)string;


-(id)initWithString:(NSString*)string;

-(FQAttributedStringRange*)range:(NSRange)range;  //指定区域,如果没有属性串或者字符串为nil则返回nil,下面方法一样。
-(FQAttributedStringRange*)allRange;      //全部字符
-(FQAttributedStringRange*)lastRange;     //最后一个字符
-(FQAttributedStringRange*)lastNRange:(NSInteger)length;  //最后N个字符
-(FQAttributedStringRange*)firstRange;    //第一个字符
-(FQAttributedStringRange*)firstNRange:(NSInteger)length;  //前面N个字符
-(FQAttributedStringRange*)characterSet:(NSCharacterSet*)characterSet;             //用于选择特殊的字符
-(FQAttributedStringRange*)includeString:(NSString*)includeString all:(BOOL)all;   //用于选择特殊的字符串
-(FQAttributedStringRange*)regularExpression:(NSString*)regularExpression all:(BOOL)all;   //正则表达式


//段落处理,以\n结尾为一段，如果没有段落则返回nil
-(FQAttributedStringRange*)firstParagraph;
-(FQAttributedStringRange*)nextParagraph;


//插入，如果为0则是头部，如果为-1则是尾部
-(void)insert:(NSInteger)pos attrstring:(NSAttributedString*)attrstring;
-(void)insert:(NSInteger)pos attrBuilder:(FQAttributeString*)attrBuilder;

-(NSAttributedString*)commit;







@end
