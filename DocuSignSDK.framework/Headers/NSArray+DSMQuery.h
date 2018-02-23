@interface NSArray (Query)

/**
 *  Returns the object in the array directly following object.
 *
 *  @param object an object
 *
 *  @return the object in the array directly following object. If object is not present or is last in the array returns nil
 */
- (id)dsm_objectAfterObject:(id)object;

/**
 *  Returns the first object subsequent to object for which the evaluationBlock returns YES.
 *
 *  @param object an object
 *  @param evaluationBlock a block which will be passed each object until it returns true or reaches the end of the array. If this is nil the directly following object will be returned.
 *
 *  @return the object in the array subsequent to object for which evaluationBlock returns YES. If object is not present or is last in the array returns nil
 */
- (id)dsm_objectAfterObject:(id)object satisfyingBlock:(BOOL(^)(id evaluatedObject, NSUInteger idx))evaluationBlock;

@end
