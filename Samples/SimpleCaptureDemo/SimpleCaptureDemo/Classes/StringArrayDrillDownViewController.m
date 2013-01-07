/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Copyright (c) 2010, Janrain, Inc.

 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.
 * Neither the name of the Janrain, Inc. nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.


 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#import "debug_log.h"
#import "StringArrayDrillDownViewController.h"
#import "JSONKit.h"
#import "Utils.h"

@interface StringElementData : NSObject
@property (strong) NSString *stringValue;
@property (strong) UILabel  *titleLabel;
@property (strong) UILabel  *subtitleLabel;
@property (strong) UIView   *editingView;
@end

@implementation StringElementData
@synthesize stringValue;
@synthesize titleLabel;
@synthesize subtitleLabel;
@synthesize editingView;
@end

@interface StringArrayDrillDownViewController ()
@property (strong) JRCaptureObject *captureObject;
@property (strong) NSArray         *tableData;
@property (strong) NSMutableArray  *localCopyArray;
@property (strong) NSMutableArray  *objectDataArray;
@property (strong) NSString        *tableHeader;
- (void)setCellTextForObjectData:(StringElementData *)objectData atIndex:(NSUInteger)index;
- (void)createCellViewsForObjectData:(StringElementData *)objectData atIndex:(NSUInteger)index;
@end

@implementation StringArrayDrillDownViewController
@synthesize captureObject;
@synthesize tableHeader;
@synthesize tableData;
@synthesize myTableView;
@synthesize myUpdateButton;
@synthesize myKeyboardToolbar;
@synthesize localCopyArray;
@synthesize objectDataArray;

- (void)setTableDataWithArray:(NSArray *)array
{
    self.tableData       = array;
    self.localCopyArray  = [[NSMutableArray alloc] initWithArray:tableData];
    self.objectDataArray = [[NSMutableArray alloc] initWithCapacity:[tableData count]];

    for (NSUInteger i = 0; i < [tableData count]; i++)
    {
        StringElementData *objectData = [[StringElementData alloc] init];

        [self createCellViewsForObjectData:objectData atIndex:i];
        [self setCellTextForObjectData:objectData atIndex:i];

        [objectDataArray addObject:objectData];
    }

    DLog(@"%@", [tableData description]);
}

- (id)initWithNibName:(NSString*)nibNameOrNil bundle:(NSBundle*)nibBundleOrNil forArray:(NSArray*)array
  captureParentObject:(JRCaptureObject*)parentObject andKey:(NSString*)key
{
    if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]))
    {
        self.captureObject = parentObject;
        self.tableHeader   = key;

        [self setTableDataWithArray:array];
    }

    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    UIBarButtonItem *editButton = [[UIBarButtonItem alloc]
                                initWithBarButtonSystemItem:UIBarButtonSystemItemEdit
                                                     target:self
                                                     action:@selector(editButtonPressed:)];

    self.navigationItem.rightBarButtonItem         = editButton;
    self.navigationItem.rightBarButtonItem.enabled = YES;

    self.navigationItem.rightBarButtonItem.style   = UIBarButtonItemStyleBordered;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [myTableView reloadData];
}

- (IBAction)doneEditingTextButtonPressed:(id)sender
{
    [firstResponder resignFirstResponder];
}

- (void)editButtonPressed:(id)sender
{
    DLog(@"");
    UIBarButtonItem *doneButton = [[UIBarButtonItem alloc]
                                initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                                     target:self
                                                     action:@selector(doneButtonPressed:)];

    self.navigationItem.rightBarButtonItem         = doneButton;
    self.navigationItem.rightBarButtonItem.enabled = YES;

    self.navigationItem.rightBarButtonItem.style   = UIBarButtonItemStyleBordered;

    isEditing = YES;

    [myTableView reloadData];
}

- (void)doneButtonPressed:(id)sender
{
    DLog(@"");
    UIBarButtonItem *editButton = [[UIBarButtonItem alloc]
                                initWithBarButtonSystemItem:UIBarButtonSystemItemEdit
                                                     target:self
                                                     action:@selector(editButtonPressed:)];

    self.navigationItem.rightBarButtonItem         = editButton;
    self.navigationItem.rightBarButtonItem.enabled = YES;

    self.navigationItem.rightBarButtonItem.style   = UIBarButtonItemStyleBordered;

    isEditing = NO;

    [firstResponder resignFirstResponder], firstResponder = nil;
    [myTableView reloadData];
}

- (void)saveLocalArrayToCaptureObject
{
    SEL setArraySelector = NSSelectorFromString([NSString stringWithFormat:@"set%@:", upcaseFirst(tableHeader)]);

    [captureObject performSelector:setArraySelector withObject:[NSArray arrayWithArray:localCopyArray]];
}

- (IBAction)replaceButtonPressed:(id)sender
{
    DLog(@"");

    [self doneButtonPressed:nil];
    [self saveLocalArrayToCaptureObject];

    SEL replaceArraySelector =
                NSSelectorFromString([NSString stringWithFormat:@"replace%@ArrayOnCaptureForDelegate:context:",
                        [tableHeader stringByReplacingCharactersInRange:NSMakeRange(0,1)
                                                             withString:[[tableHeader substringToIndex:1] capitalizedString]]]);

    [captureObject performSelector:replaceArraySelector withObject:self withObject:nil];
}

- (void)addObjectButtonPressed:(UIButton *)sender
{
    DLog(@"");

    [localCopyArray addObject:[NSNull null]];

    StringElementData *objectData = [[StringElementData alloc] init];

    [self createCellViewsForObjectData:objectData atIndex:[objectDataArray count]];
    [self setCellTextForObjectData:objectData atIndex:[objectDataArray count]];

    [objectDataArray addObject:objectData];

    [self saveLocalArrayToCaptureObject];

    [myTableView beginUpdates];
    [myTableView insertRowsAtIndexPaths:[NSArray arrayWithObject:[NSIndexPath indexPathForRow:[localCopyArray count] - 1
                                                                                    inSection:0]]
                       withRowAnimation:UITableViewRowAnimationLeft];
    [myTableView endUpdates];
}

#define EDITING_VIEW_OFFSET 100
#define LEFT_BUTTON_OFFSET  1000
#define RIGHT_BUTTON_OFFSET 2000
#define LEFT_LABEL_OFFSET   3000
#define DATE_PICKER_OFFSET  4000

- (void)calibrateIndices
{
    for (NSUInteger i = 0; i < [objectDataArray count]; i++)
    {
        StringElementData *objectData = [objectDataArray objectAtIndex:i];
        NSInteger oldIndex = objectData.editingView.tag - EDITING_VIEW_OFFSET;

        [objectData.editingView setTag:EDITING_VIEW_OFFSET + i];
        [[objectData.editingView viewWithTag:LEFT_BUTTON_OFFSET + oldIndex] setTag:LEFT_BUTTON_OFFSET + i];
        [[objectData.editingView viewWithTag:RIGHT_BUTTON_OFFSET + oldIndex] setTag:RIGHT_BUTTON_OFFSET + i];

        [self setCellTextForObjectData:objectData atIndex:i];
    }
}

- (void)deleteObjectButtonPressed:(UIButton *)sender
{
    DLog(@"");
    NSUInteger itemIndex = (NSUInteger) (sender.tag - LEFT_BUTTON_OFFSET);

    [localCopyArray removeObjectAtIndex:itemIndex];
    [objectDataArray removeObjectAtIndex:itemIndex];

    [self saveLocalArrayToCaptureObject];

    [myTableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:[NSIndexPath indexPathForRow:itemIndex inSection:0]]
                       withRowAnimation:UITableViewRowAnimationLeft];

    [self calibrateIndices];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return tableHeader;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (tableHeader)
        return 30.0;
    return 0;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    if (isEditing)
        return 260;
    return 0;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [localCopyArray count] + 1;
}

- (UIView *)getTextFieldWithKeyboardType:(UIKeyboardType)keyboardType
{
    UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(20, 23,
            (UIInterfaceOrientationIsPortrait(self.interfaceOrientation)) ? 280 : 440, 22)];

    textField.backgroundColor = [UIColor clearColor];
    textField.font            = [UIFont systemFontOfSize:14.0];
    textField.textColor       = [UIColor blackColor];
    textField.textAlignment   = UITextAlignmentLeft;
    textField.hidden          = YES;
    textField.borderStyle     = UITextBorderStyleLine;
    textField.clearButtonMode = UITextFieldViewModeWhileEditing;
    textField.delegate        = self;
    textField.keyboardType    = keyboardType;

    [textField setInputAccessoryView:myKeyboardToolbar];
    [textField setAutoresizingMask:UIViewAutoresizingNone | UIViewAutoresizingFlexibleWidth];

    return textField;
}

- (void)setCellTextForObjectData:(StringElementData *)objectData atIndex:(NSUInteger)index
{
    NSString *key   = [NSString stringWithFormat:@"%@[%d]", tableHeader, index];
    id value = [localCopyArray objectAtIndex:index];

    if (value == [NSNull null]) value = @"null element";

    objectData.titleLabel.text    = key;
    objectData.subtitleLabel.text = value;
}

- (void)createCellViewsForObjectData:(StringElementData *)objectData atIndex:(NSUInteger)index
{
    NSInteger editingViewTag = EDITING_VIEW_OFFSET + index;

    CGRect frame = CGRectMake(10, 5, (UIInterfaceOrientationIsPortrait(self.interfaceOrientation)) ? 280 : 440, 18);

    UILabel *keyLabel = [[UILabel alloc] initWithFrame:frame];

    keyLabel.backgroundColor  = [UIColor clearColor];
    keyLabel.font             = [UIFont systemFontOfSize:13.0];
    keyLabel.textColor        = [UIColor grayColor];
    keyLabel.textAlignment    = UITextAlignmentLeft;
    keyLabel.autoresizingMask = UIViewAutoresizingNone | UIViewAutoresizingFlexibleWidth;

    [objectData setTitleLabel:keyLabel];

    frame.origin.y     += 16;
    frame.size.height  += 8;

    UILabel *valueLabel = [[UILabel alloc] initWithFrame:frame];

    valueLabel.backgroundColor  = [UIColor clearColor];
    valueLabel.font             = [UIFont boldSystemFontOfSize:16.0];
    valueLabel.textColor        = [UIColor grayColor];
    valueLabel.textAlignment    = UITextAlignmentLeft;
    valueLabel.autoresizingMask = UIViewAutoresizingNone | UIViewAutoresizingFlexibleWidth;

    [objectData setSubtitleLabel:valueLabel];

    UIView *editingView = [self getTextFieldWithKeyboardType:UIKeyboardTypeDefault];

    [editingView setTag:editingViewTag];
    [editingView setAutoresizingMask:UIViewAutoresizingNone | UIViewAutoresizingFlexibleWidth];

    [objectData setEditingView:editingView];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    DLog(@"");

    UITableViewCellStyle style = UITableViewCellStyleDefault;
    NSString *reuseIdentifier  = (indexPath.row == [localCopyArray count]) ? @"lastCell" : @"cachedCell";

    UITableViewCell *cell =
        [tableView dequeueReusableCellWithIdentifier:reuseIdentifier];

    if (cell == nil) cell = [[UITableViewCell alloc] initWithStyle:style reuseIdentifier:reuseIdentifier];

    if (indexPath.row == [localCopyArray count])
    {
        cell.selectionStyle = UITableViewCellSelectionStyleBlue;
        cell.textLabel.text = [NSString stringWithFormat:@"Add another %@ object", tableHeader];
    }
    else
    {
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        StringElementData *objectData = [objectDataArray objectAtIndex:(NSUInteger)indexPath.row];

        for (UIView *view in [cell.contentView subviews]) [view removeFromSuperview];

        UILabel *titleLabel    = objectData.titleLabel;
        UILabel *subtitleLabel = objectData.subtitleLabel;
        UIView  *editingView   = objectData.editingView;

        [cell.contentView addSubview:titleLabel];
        [cell.contentView addSubview:subtitleLabel];
        [cell.contentView addSubview:editingView];

        [editingView setHidden:!isEditing];
        [subtitleLabel setHidden:isEditing];
    }

    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    DLog(@"");
    [tableView deselectRowAtIndexPath:indexPath animated:NO];

    if (indexPath.row == [localCopyArray count])
    {
        [self addObjectButtonPressed:nil];
    }
}

- (void)replaceArrayDidFailForObject:(JRCaptureObject *)object arrayNamed:(NSString *)arrayName 
                           withError:(NSError *)error context:(NSObject *)context
{
    DLog(@"");
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Error"
                                                        message:error.localizedFailureReason
                                                       delegate:nil
                                              cancelButtonTitle:@"Dismiss"
                                              otherButtonTitles:nil];
    [alertView show];
}

- (void)replaceArrayDidSucceedForObject:(JRCaptureObject *)object newArray:(NSArray *)replacedArray 
                                  named:(NSString *)arrayName context:(NSObject *)context
{
    DLog(@"");
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Success"
                                                        message:[replacedArray JSONString]
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
    [alertView show];

    [self setTableDataWithArray:replacedArray];
    [myTableView reloadData];

    [SharedData resaveCaptureUser];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return (toInterfaceOrientation == UIInterfaceOrientationPortrait);
}

@end

