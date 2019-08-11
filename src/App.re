open ReactNative;

[@bs.val] external alert : string => unit = "alert" ;

let styles = Style.(StyleSheet.create({
    "container": style(~flex=1., ~justifyContent=`center, ()),
    "buttonContainer": style(~margin=dp(20.), ()),
    "alternativeLayoutButtonContainer": style(~margin=dp(20.), ~flexDirection=`row, ~justifyContent=`spaceBetween, ()),
}));

module ButtonBasics = {
    let onPress = (_) => alert("You tapped the button!");

    [@react.component]
    let make = () => {
        <View style=styles##container>
            <View style=styles##buttonContainer>
                <Button onPress title="Press me"/>
            </View>
            <View style=styles##buttonContainer>
                <Button onPress title="Press me" color="#841584"/>
            </View>
            <View style=styles##alternativeLayoutButtonContainer>
                <Button onPress title="This looks great!"/>
                <Button onPress title="OK!" color="#841584"/>
            </View>
        </View>
    }
}

[@react.component]
let app = () => {
    /*<View style=Style.style(
        ~flex=1.,
        ~flexDirection=`column,
        ~justifyContent=`center,
        ~alignItems=`center,
        ~flexWrap=`wrap,
        ())>*/
        <ButtonBasics/>
    //</View>
};
