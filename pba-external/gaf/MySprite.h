//
//  MySprite.hpp
//  GAFPlayer
//
//  Created by Kaushik Poria on 04/05/17.
//
//  MySprite is exact replica of MySprite class of cocos2dx 3.13

#ifndef MySprite_hpp
#define MySprite_hpp

#include <string>
#include "2d/CCNode.h"
#include "2d/CCDrawNode.h"
#include "base/CCProtocols.h"
#include "renderer/CCTextureAtlas.h"
#include "renderer/CCTrianglesCommand.h"
#include "renderer/CCCustomCommand.h"
#include "2d/CCAutoPolygon.h"

NS_CC_BEGIN

class SpriteBatchNode;
class SpriteFrame;
class Animation;
class Rect;
class Size;
class Texture2D;
struct transformValues_;

#ifdef SPRITE_RENDER_IN_SUBPIXEL
#undef SPRITE_RENDER_IN_SUBPIXEL
#endif

#if CC_SPRITEBATCHNODE_RENDER_SUBPIXEL
#define SPRITE_RENDER_IN_SUBPIXEL
#else
#define SPRITE_RENDER_IN_SUBPIXEL(__ARGS__) (ceil(__ARGS__))
#endif

class MySprite : public Node, public TextureProtocol
{
public:
    /** MySprite invalid index on the SpriteBatchNode. */
    static const int INDEX_NOT_INITIALIZED = -1;
    
    /// @name Creators
    /// @{
    
    /**
     * Creates an empty sprite without texture. You can call setTexture method subsequently.
     *
     * @memberof MySprite
     * @return An autoreleased sprite object.
     */
    static MySprite* create();
    
    /**
     * Creates a sprite with an image filename.
     *
     * After creation, the rect of sprite will be the size of the image,
     * and the offset will be (0,0).
     *
     * @param   filename A path to image file, e.g., "scene1/monster.png".
     * @return  An autoreleased sprite object.
     */
    static MySprite* create(const std::string& filename);
    
    /**
     * Creates a polygon sprite with a polygon info.
     *
     * After creation, the rect of sprite will be the size of the image,
     * and the offset will be (0,0).
     *
     * @param   polygonInfo A path to image file, e.g., "scene1/monster.png".
     * @return  An autoreleased sprite object.
     */
    static MySprite* create(const PolygonInfo& info);
    
    /**
     * Creates a sprite with an image filename and a rect.
     *
     * @param   filename A path to image file, e.g., "scene1/monster.png".
     * @param   rect     A subrect of the image file.
     * @return  An autoreleased sprite object.
     */
    static MySprite* create(const std::string& filename, const Rect& rect);
    
    /**
     * Creates a sprite with a Texture2D object.
     *
     * After creation, the rect will be the size of the texture, and the offset will be (0,0).
     *
     * @param   texture    A pointer to a Texture2D object.
     * @return  An autoreleased sprite object.
     */
    static MySprite* createWithTexture(Texture2D *texture);
    
    /**
     * Creates a sprite with a texture and a rect.
     *
     * After creation, the offset will be (0,0).
     *
     * @param   texture     A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
     * @param   rotated     Whether or not the rect is rotated.
     * @return  An autoreleased sprite object.
     */
    static MySprite* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false);
    
    /**
     * Creates a sprite with an sprite frame.
     *
     * @param   spriteFrame    A sprite frame which involves a texture and a rect.
     * @return  An autoreleased sprite object.
     */
    static MySprite* createWithSpriteFrame(SpriteFrame *spriteFrame);
    
    /**
     * Creates a sprite with an sprite frame name.
     *
     * A SpriteFrame will be fetched from the SpriteFrameCache by spriteFrameName param.
     * If the SpriteFrame doesn't exist it will raise an exception.
     *
     * @param   spriteFrameName A null terminated string which indicates the sprite frame name.
     * @return  An autoreleased sprite object.
     */
    static MySprite* createWithSpriteFrameName(const std::string& spriteFrameName);
    
    //  end of creators group
    /// @}
    
    
    /// @{
    /// @name BatchNode methods
    
    /**
     * Updates the quad according the rotation, position, scale values.
     */
    virtual void updateTransform() override;
    
    /**
     * Returns the batch node object if this sprite is rendered by SpriteBatchNode.
     *
     * @return The SpriteBatchNode object if this sprite is rendered by SpriteBatchNode,
     *         nullptr if the sprite isn't used batch node.
     */
    virtual SpriteBatchNode* getBatchNode() const;
    /**
     * Sets the batch node to sprite.
     * @warning This method is not recommended for game developers. Sample code for using batch node
     * @code
     * SpriteBatchNode *batch = SpriteBatchNode::create("Images/grossini_dance_atlas.png", 15);
     * MySprite *sprite = MySprite::createWithTexture(batch->getTexture(), Rect(0, 0, 57, 57));
     * batch->addChild(sprite);
     * layer->addChild(batch);
     * @endcode
     */
    virtual void setBatchNode(SpriteBatchNode *spriteBatchNode);
    
    /// @} end of BatchNode methods
    
    
    /// @{
    /// @name Texture / Frame methods
    
    /** Sets a new texture (from a filename) to the sprite.
     *
     *  @memberof MySprite
     *  It will call `setTextureRect()` with the texture's content size.
     */
    virtual void setTexture(const std::string &filename );
    
    /** @overload
     *
     *  The Texture's rect is not changed.
     */
    virtual void setTexture(Texture2D *texture) override;
    
    /** Returns the Texture2D object used by the sprite. */
    virtual Texture2D* getTexture() const override;
    
    /**
     * Updates the texture rect of the MySprite in points.
     *
     * It will call setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize) with \p rotated = false, and \p utrimmedSize = rect.size.
     */
    virtual void setTextureRect(const Rect& rect);
    
    /** @overload
     *
     * It will update the texture coordinates and the vertex rectangle.
     */
    virtual void setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize);
    
    /**
     * Sets the vertex rect.
     *
     * It will be called internally by setTextureRect.
     * Useful if you want to create 2x images from SD images in Retina Display.
     * Do not call it manually. Use setTextureRect instead.
     */
    virtual void setVertexRect(const Rect& rect);
    
    /** @{
     * Sets a new SpriteFrame to the MySprite.
     */
    virtual void setSpriteFrame(const std::string &spriteFrameName);
    virtual void setSpriteFrame(SpriteFrame* newFrame);
    /** @} */
    
    /** @deprecated Use `setSpriteFrame()` instead. */
    CC_DEPRECATED_ATTRIBUTE virtual void setDisplayFrame(SpriteFrame *newFrame) { setSpriteFrame(newFrame); }
    
    /**
     * Returns whether or not a SpriteFrame is being displayed.
     */
    virtual bool isFrameDisplayed(SpriteFrame *frame) const;
    
    /**
     * Returns the current displayed frame.
     */
    virtual SpriteFrame* getSpriteFrame() const;
    /** @deprecated Use `getSpriteFrame()` instead.
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE virtual SpriteFrame* getDisplayFrame() const { return getSpriteFrame(); }
    /** @deprecated Use `getSpriteFrame()` instead. */
    CC_DEPRECATED_ATTRIBUTE virtual SpriteFrame* displayFrame() const { return getSpriteFrame(); };
    
    /// @} End of frames methods
    
    
    /// @{
    /// @name Animation methods
    /**
     * Changes the display frame with animation name and index.
     * The animation name will be get from the AnimationCache.
     */
    virtual void setDisplayFrameWithAnimationName(const std::string& animationName, ssize_t frameIndex);
    /// @}
    
    
    /// @{
    /// @name MySprite Properties' setter/getters.
    
    /**
     * Whether or not the MySprite needs to be updated in the Atlas.
     *
     * @return True if the sprite needs to be updated in the Atlas, false otherwise.
     */
    virtual bool isDirty() const { return _dirty; }
    
    /**
     * Makes the MySprite to be updated in the Atlas.
     */
    virtual void setDirty(bool dirty) { _dirty = dirty; }
    
    /**
     * Returns the quad (tex coords, vertex coords and color) information.
     * @js  NA
     * @lua NA
     */
    inline V3F_C4B_T2F_Quad getQuad() const { return _quad; }
    
    /**
     * Returns whether or not the texture rectangle is rotated.
     */
    inline bool isTextureRectRotated() const { return _rectRotated; }
    
    /**
     * Returns the index used on the TextureAtlas.
     */
    inline ssize_t getAtlasIndex() const { return _atlasIndex; }
    
    /**
     * Sets the index used on the TextureAtlas.
     *
     * @warning Don't modify this value unless you know what you are doing.
     */
    inline void setAtlasIndex(ssize_t atlasIndex) { _atlasIndex = atlasIndex; }
    
    /**
     * Returns the rect of the MySprite in points.
     */
    inline const Rect& getTextureRect() const { return _rect; }
    
    /**
     * Gets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
     */
    inline TextureAtlas* getTextureAtlas() const { return _textureAtlas; }
    
    /**
     * Sets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
     */
    inline void setTextureAtlas(TextureAtlas *textureAtlas) { _textureAtlas = textureAtlas; }
    
    /**
     * Gets the offset position of the sprite. Calculated automatically by editors like Zwoptex.
     */
    inline const Vec2& getOffsetPosition() const { return _offsetPosition; }
    
    
    /**
     * Returns the flag which indicates whether the sprite is flipped horizontally or not.
     *
     * It only flips the texture of the sprite, and not the texture of the sprite's children.
     * Also, flipping the texture doesn't alter the anchorPoint.
     * If you want to flip the anchorPoint too, and/or to flip the children too use:
     * sprite->setScaleX(sprite->getScaleX() * -1);
     *
     * @return true if the sprite is flipped horizontally, false otherwise.
     */
    bool isFlippedX() const;
    /**
     * Sets whether the sprite should be flipped horizontally or not.
     *
     * @param flippedX true if the sprite should be flipped horizontally, false otherwise.
     */
    void setFlippedX(bool flippedX);
    
    /** @deprecated Use isFlippedX() instead.
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE bool isFlipX() { return isFlippedX(); };
    /** @deprecated Use setFlippedX() instead
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE void setFlipX(bool flippedX) { setFlippedX(flippedX); };
    
    /**
     * Return the flag which indicates whether the sprite is flipped vertically or not.
     *
     * It only flips the texture of the sprite, and not the texture of the sprite's children.
     * Also, flipping the texture doesn't alter the anchorPoint.
     * If you want to flip the anchorPoint too, and/or to flip the children too use:
     * sprite->setScaleY(sprite->getScaleY() * -1);
     *
     * @return true if the sprite is flipped vertically, false otherwise.
     */
    bool isFlippedY() const;
    /**
     * Sets whether the sprite should be flipped vertically or not.
     *
     * @param flippedY true if the sprite should be flipped vertically, false otherwise.
     */
    void setFlippedY(bool flippedY);
    
    /// @} End of MySprite properties getter/setters
    
    /** @deprecated Use isFlippedY() instead.
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE bool isFlipY() { return isFlippedY(); };
    /** @deprecated Use setFlippedY() instead.
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE void setFlipY(bool flippedY) { setFlippedY(flippedY); };
    
    /**
     * returns a reference of the polygon information associated with this sprite
     *
     * @return a reference of PolygonInfo
     */
    const PolygonInfo& getPolygonInfo() const;
    
    /**
     * set the sprite to use this new PolygonInfo
     *
     * @param PolygonInfo the polygon information object
     */
    void setPolygonInfo(const PolygonInfo& info);
    //
    // Overrides
    //
    /// @{
    /// @name Functions inherited from TextureProtocol.
    /**
     *@code
     *When this function bound into js or lua,the parameter will be changed.
     *In js: var setBlendFunc(var src, var dst).
     *In lua: local setBlendFunc(local src, local dst).
     *@endcode
     */
    inline void setBlendFunc(const BlendFunc &blendFunc) override { _blendFunc = blendFunc; }
    /**
     * @js  NA
     * @lua NA
     */
    inline const BlendFunc& getBlendFunc() const override { return _blendFunc; }
    /// @}
    
    /**
     * @js NA
     */
    virtual std::string getDescription() const override;
    
    /// @{
    /// @name Functions inherited from Node.
    virtual void setScaleX(float scaleX) override;
    virtual void setScaleY(float scaleY) override;
    virtual void setScale(float scaleX, float scaleY) override;
    /**
     * @js  NA
     * @lua NA
     */
    virtual void setPosition(const Vec2& pos) override;
    virtual void setPosition(float x, float y) override;
    virtual void setRotation(float rotation) override;
    virtual void setRotationSkewX(float rotationX) override;
    virtual void setRotationSkewY(float rotationY) override;
    virtual void setSkewX(float sx) override;
    virtual void setSkewY(float sy) override;
    virtual void removeChild(Node* child, bool cleanup) override;
    virtual void removeAllChildrenWithCleanup(bool cleanup) override;
    virtual void reorderChild(Node *child, int zOrder) override;
    using Node::addChild;
    virtual void addChild(Node *child, int zOrder, int tag) override;
    virtual void addChild(Node *child, int zOrder, const std::string &name) override;
    virtual void sortAllChildren() override;
    virtual void setScale(float scale) override;
    virtual void setPositionZ(float positionZ) override;
    virtual void setAnchorPoint(const Vec2& anchor) override;
    
    virtual void setIgnoreAnchorPointForPosition(bool value) override;
    
    virtual void setVisible(bool bVisible) override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    virtual void setOpacityModifyRGB(bool modify) override;
    virtual bool isOpacityModifyRGB() const override;
    /// @}
    
    int getResourceType() const { return _fileType; }
    const std::string& getResourceName() const { return _fileName; }
    
    CC_CONSTRUCTOR_ACCESS :
    /**
     * @js ctor
     */
    MySprite();
    virtual ~MySprite();
    
    /* Initializes an empty sprite with no parameters. */
    virtual bool init() override;
    
    /**
     * Initializes a sprite with a texture.
     *
     * After initialization, the rect used will be the size of the texture, and the offset will be (0,0).
     *
     * @param   texture    A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithTexture(Texture2D *texture);
    
    
    /**
     * Initializes a sprite with a PolygonInfo.
     *
     * After initialization, the rect used will be the size of the texture, and the offset will be (0,0).
     *
     * @param   PolygonInfo    a Polygon info contains the structure of the polygon.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithPolygon(const PolygonInfo& info);
    
    /**
     * Initializes a sprite with a texture and a rect.
     *
     * After initialization, the offset will be (0,0).
     *
     * @param   texture    A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @param   rect        Only the contents inside rect of this texture will be applied for this sprite.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithTexture(Texture2D *texture, const Rect& rect);
    
    /**
     * Initializes a sprite with a texture and a rect in points, optionally rotated.
     *
     * After initialization, the offset will be (0,0).
     * @note    This is the designated initializer.
     *
     * @param   texture    A Texture2D object whose texture will be applied to this sprite.
     * @param   rect        A rectangle assigned the contents of texture.
     * @param   rotated     Whether or not the texture rectangle is rotated.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithTexture(Texture2D *texture, const Rect& rect, bool rotated);
    
    /**
     * Initializes a sprite with an SpriteFrame. The texture and rect in SpriteFrame will be applied on this sprite.
     *
     * @param   spriteFrame  A SpriteFrame object. It should includes a valid texture and a rect.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithSpriteFrame(SpriteFrame *spriteFrame);
    
    /**
     * Initializes a sprite with an sprite frame name.
     *
     * A SpriteFrame will be fetched from the SpriteFrameCache by name.
     * If the SpriteFrame doesn't exist it will raise an exception.
     *
     * @param   spriteFrameName  A key string that can fetched a valid SpriteFrame from SpriteFrameCache.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithSpriteFrameName(const std::string& spriteFrameName);
    
    /**
     * Initializes a sprite with an image filename.
     *
     * This method will find filename from local file system, load its content to Texture2D,
     * then use Texture2D to create a sprite.
     * After initialization, the rect used will be the size of the image. The offset will be (0,0).
     *
     * @param   filename The path to an image file in local file system.
     * @return  True if the sprite is initialized properly, false otherwise.
     * @lua     init
     */
    virtual bool initWithFile(const std::string& filename);
    
    /**
     * Initializes a sprite with an image filename, and a rect.
     *
     * This method will find filename from local file system, load its content to Texture2D,
     * then use Texture2D to create a sprite.
     * After initialization, the offset will be (0,0).
     *
     * @param   filename The path to an image file in local file system.
     * @param   rect        The rectangle assigned the content area from texture.
     * @return  True if the sprite is initialized properly, false otherwise.
     * @lua     init
     */
    virtual bool initWithFile(const std::string& filename, const Rect& rect);
    
protected:
    
    void updateColor() override;
    virtual void setTextureCoords(const Rect& rect);
    virtual void updateBlendFunc();
    virtual void setReorderChildDirtyRecursively();
    virtual void setDirtyRecursively(bool value);
    
    
    
    //
    // Data used when the sprite is rendered using a SpriteSheet
    //
    TextureAtlas*       _textureAtlas;      /// SpriteBatchNode texture atlas (weak reference)
    ssize_t             _atlasIndex;        /// Absolute (real) Index on the SpriteSheet
    SpriteBatchNode*    _batchNode;         /// Used batch node (weak reference)
    
    bool                _dirty;             /// Whether the sprite needs to be updated
    bool                _recursiveDirty;    /// Whether all of the sprite's children needs to be updated
    bool                _shouldBeHidden;    /// should not be drawn because one of the ancestors is not visible
    Mat4              _transformToBatch;
    
    //
    // Data used when the sprite is self-rendered
    //
    BlendFunc        _blendFunc;            /// It's required for TextureProtocol inheritance
    Texture2D*       _texture;              /// Texture2D object that is used to render the sprite
    SpriteFrame*     _spriteFrame;
    TrianglesCommand _trianglesCommand;     ///
#if CC_SPRITE_DEBUG_DRAW
    DrawNode *_debugDrawNode;
#endif //CC_SPRITE_DEBUG_DRAW
    //
    // Shared data
    //
    
    // texture
    Rect _rect;                             /// Rectangle of Texture2D
    bool   _rectRotated;                    /// Whether the texture is rotated
    
    // Offset Position (used by Zwoptex)
    Vec2 _offsetPosition;
    Vec2 _unflippedOffsetPositionFromCenter;
    
    // vertex coords, texture coords and color info
    V3F_C4B_T2F_Quad _quad;
    PolygonInfo  _polyInfo;
    
    // opacity and RGB protocol
    bool _opacityModifyRGB;
    
    // image is flipped
    bool _flippedX;                         /// Whether the sprite is flipped horizontally or not
    bool _flippedY;                         /// Whether the sprite is flipped vertically or not
    
    bool _insideBounds;                     /// whether or not the sprite was inside bounds the previous frame
    
    std::string _fileName;
    int _fileType;
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(MySprite);
};

NS_CC_END

#endif /* MySprite_hpp */
