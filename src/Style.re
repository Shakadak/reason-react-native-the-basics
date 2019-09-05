open ReactNative;

let styles = StyleSheet.create({
    "bigBlue": Style.style(~color="blue", ~fontWeight=`bold, ~fontSize=30., ()),
    "red": Style.style(~color="red", ()),
});

[@react.component]
let make = () => {
    <View>
        <Text style=styles##red>"just red"->React.string</Text>
        <Text style=styles##bigBlue>"just bigBlue"->React.string</Text>
        <Text style=Style.array([|styles##bigBlue, styles##red|])>{React.string("bigBlue, then red")}</Text>
        <Text style=Style.array([|styles##red, styles##bigBlue|])>{React.string("red, then bigBlue")}</Text>
    </View>
};
