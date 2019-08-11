open ReactNative;

[@bs.val] external alert : string => unit = "alert" ;

let styles = Style.(StyleSheet.create({
    "container": style(~paddingTop=dp(60.), ~alignItems=`center, ()),
    "button": style(~marginBottom=dp(30.), ~width=dp(260.), ~alignItems=`center, ~backgroundColor="#2196F3", ()),
    "buttonText": style(~textAlign=`center, ~padding=dp(20.), ~color="white", ()),
}));

module ButtonBasics = {
    let onPress = (_) => alert("You tapped the button!");
    let onLongPress = (_) => alert("You long-pressed the button!");

    [@react.component]
    let make = () => {
        <View style=styles##container>
            <TouchableHighlight onPress underlayColor="white">
                <View style=styles##button>
                    <Text style=styles##buttonText>{React.string("TouchableHighlight")}</Text>
                </View>
            </TouchableHighlight>
            <TouchableOpacity onPress>
                <View style=styles##button>
                    <Text style=styles##buttonText>{React.string("TouchableOpacity")}</Text>
                </View>
            </TouchableOpacity>
            <TouchableNativeFeedback
                onPress
                background=?{Platform.os == Platform.android ? Some(TouchableNativeFeedback.Background.selectableBackground()) : None}>
                <View style=styles##button>
                    <Text style=styles##buttonText>{React.string("TouchableNativeFeedback " ++ (Platform.os == Platform.android ? "(Android only)" : ""))}</Text>
                </View>
            </TouchableNativeFeedback>
            <TouchableWithoutFeedback onPress>
                <View style=styles##button>
                    <Text style=styles##buttonText>{React.string("TouchableWithoutFeedback")}</Text>
                </View>
            </TouchableWithoutFeedback>
            <TouchableHighlight onPress onLongPress underlayColor="white">
                <View style=styles##button>
                    <Text style=styles##buttonText>{React.string("Touchable with Long Press")}</Text>
                </View>
            </TouchableHighlight>
        </View>
    }
}

[@react.component]
let app = () => {
        <ButtonBasics/>
};
